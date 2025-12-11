from pymongo import MongoClient
import pandas as pd
import matplotlib.pyplot as plt

class AnimalShelter(object):
    """ CRUD operations and analytical processing for Animal collection in MongoDB """

    def __init__(self, USER, PASS):
        # Force credentials to match the course environment
        USER = 'aacuser'
        PASS = 'Frontporch1'
        HOST = 'nv-desktop-services.apporto.com'
        PORT = 32390
        DB = 'AAC'
        COL = 'animals'

        try:
            self.client = MongoClient(f"mongodb://{USER}:{PASS}@{HOST}:{PORT}/{DB}?authSource=admin")
            self.database = self.client[DB]
            self.collection = self.database[COL]
        except Exception as e:
            print(f"Failed to connect to MongoDB: {e}")
            raise

    # --------------------------
    # CRUD METHODS
    # --------------------------

    def create(self, data, lookup):
        if not data or not isinstance(data, dict):
            raise ValueError("Invalid data: must be a non-empty dictionary.")
        if not lookup or not isinstance(lookup, dict):
            raise ValueError("Invalid lookup: must be a non-empty dictionary.")

        try:
            if self.collection.find_one(lookup):
                return False

            result = self.collection.insert_one(data)
            return result.acknowledged
        except Exception as e:
            print(f"Error inserting document: {e}")
            return False

    def read(self, query: dict = None):
        try:
            if query is None:
                query = {}
            result = self.collection.find(query)
            return list(result)
        except Exception as e:
            print(f"Error reading documents: {e}")
            return []

    def update(self, query: dict, update_data: dict):
        if not query or not isinstance(query, dict):
            raise ValueError("Invalid query.")
        if not update_data or not isinstance(update_data, dict):
            raise ValueError("Invalid update data.")

        try:
            result = self.collection.update_many(query, update_data)
            return result.modified_count
        except Exception as e:
            print(f"Error updating documents: {e}")
            return 0

    def delete(self, query: dict):
        if not query or not isinstance(query, dict):
            raise ValueError("Invalid query.")

        try:
            result = self.collection.delete_many(query)
            return result.deleted_count
        except Exception as e:
            print(f"Error deleting documents: {e}")
            return 0

    # -----------------------------------------------------------
    # ENHANCEMENTS FOR EPORTFOLIO
    # -----------------------------------------------------------

    def analyze_adoptions(self):
        """
        Returns adoption counts grouped by breed.
        Equivalent to: How many animals of each breed were adopted?
        """
        pipeline = [
            {"$match": {"outcome_type": "Adoption"}},
            {"$group": {"_id": "$breed", "adoption_count": {"$sum": 1}}},
            {"$sort": {"adoption_count": -1}}
        ]

        try:
            results = list(self.collection.aggregate(pipeline))
            # Convert to clean list of dicts
            analysis = [{"breed": r["_id"], "adoptions": r["adoption_count"]} for r in results]
            return pd.DataFrame(analysis)
        except Exception as e:
            print(f"Error analyzing adoptions: {e}")
            return pd.DataFrame()

    def seasonal_adoption_trends(self, show_plot=True):
        """
        Analyzes adoption counts by month.
        Returns DataFrame and optionally displays a matplotlib line chart.
        """
        pipeline = [
            {"$match": {"outcome_type": "Adoption"}},
            {"$project": {"month": {"$month": "$date_of_birth"}}},
            {"$group": {"_id": "$month", "adoptions": {"$sum": 1}}},
            {"$sort": {"_id": 1}}
        ]

        try:
            results = list(self.collection.aggregate(pipeline))
            df = pd.DataFrame(results)
            df.rename(columns={"_id": "month"}, inplace=True)

            # Show matplotlib trend line
            if show_plot and not df.empty:
                plt.figure(figsize=(10, 6))
                plt.plot(df["month"], df["adoptions"], marker='o')
                plt.title("Seasonal Adoption Trends by Month")
                plt.xlabel("Month")
                plt.ylabel("Number of Adoptions")
                plt.grid(True)
                plt.show()

            return df

        except Exception as e:
            print(f"Error computing seasonal adoption trends: {e}")
            return pd.DataFrame()
