# CS499_Capstone

# Professional Self-Assessment

![Python](https://img.shields.io/badge/Python-Programming-blue)
![SQL](https://img.shields.io/badge/SQL-Databases-orange)
![MongoDB](https://img.shields.io/badge/MongoDB-NoSQL-green)
![Android](https://img.shields.io/badge/Android-Mobile%20Development-brightgreen)
![GitHub](https://img.shields.io/badge/GitHub-Version%20Control-black)

---

## Table of Contents
- [About This Portfolio](#about-this-portfolio)
- [Professional Self-Assessment](#professional-self-assessment)
- [Core Technical Competencies](#core-technical-competencies)
- [Portfolio Artifacts Overview](#portfolio-artifacts-overview)
  - [Software Engineering and Design](#software-engineering-and-design)
  - [Algorithms and Data Structures](#algorithms-and-data-structures)
  - [Databases and Analytics](#databases-and-analytics)

---

## About This Portfolio

You can view the full repository here: [CS499 Capstone GitHub Repository](https://github.com/SteveArevalo/CS499_CapStone)

This repository serves as my professional Computer Science ePortfolio and capstone submission for Southern New Hampshire University. It highlights my academic and technical growth across software engineering, data structures and algorithms, database systems, analytics, and security. All artifacts contained within this repository were developed or enhanced as part of my undergraduate Computer Science program and collectively demonstrate my readiness for a data role.


---

## Professional Self-Assessment

Completing the Computer Science program and developing my ePortfolio has been instrumental in shaping my professional goals and preparing me for a career as a data engineer. While there were times when the coursework and projects felt especially challenging and at times overwhelming, my drive for knowledge and determination to solve complex problems persevered. Throughout the program, I gained hands-on experience designing, analyzing, and enhancing systems that manage, process, and extract value from data. The capstone experience required me to critically reflect on my coursework, refine technical artifacts, and intentionally demonstrate how my skills align with industry expectations. This process not only strengthened my technical confidence but also clarified my professional values around data quality and system reliability, ultimately positioning me to be immediately employable in data focused roles.

Collaboration and communication were emphasized consistently throughout my coursework and project work. In team-based assignments, I worked within structured development environments that required task coordination, shared ownership of deliverables, and iterative feedback. These experiences reinforced the importance of collaboration when building reliable software and data systems. I also developed strong stakeholder communication skills by producing technical documentation, project narratives, and data-driven explanations tailored to non-technical audiences. For example, in my CS 340 coursework, I learned how to clearly explain trends, metrics, and system behavior so that stakeholders could make informed decisions based on the shelter data rather than the implementation details.

The CS 300 course significantly strengthened my understanding of **data structures and algorithms** and their role in building efficient, scalable systems. Through applied coursework, I evaluated algorithmic performance using Big-O notation and implemented data structures that optimize data access and processing. This is exemplified by my enhancement of a Binary Search Tree into a self-balancing AVL Tree, which improved worst-case performance from **O(n)** to **O(log n)**. This experience reflects my ability to evaluate trade-offs in design decisions and implement algorithmic solutions that scale as data volume increases—an essential skill for data engineering.

My **software engineering and database skills** were developed through CS 360, as it required designing maintainable architectures and managing data across multiple layers of a system. In my *Inventory Management App*, originally developed for **Mobile Architecture and Programming**, I enhanced the application by refactoring it to follow the **MVVM architectural pattern**. This improvement separated concerns between the user interface, business logic, and data layer, improving maintainability, scalability, and testability. 

**Security awareness** was integrated throughout my coursework and project enhancements, shaping how I approach system and data design. I developed an understanding of access control, secure data handling, and potential vulnerabilities in software architecture. Rather than treating security as an afterthought, I applied a security mindset when designing data access layers, managing databases, and structuring application logic. This approach is especially relevant in data engineering roles, where protecting data integrity, privacy, and availability is critical.

The artifacts included in this ePortfolio collectively demonstrate the full range of my computer science skills and how they intersect in real-world applications. The **software engineering artifact** highlights my ability to design scalable and maintainable systems, the **algorithms and data structures artifact** demonstrates performance optimization and analytical reasoning, and the **database and analytics artifact** showcases my ability to transform raw data into actionable insights. Together, these projects illustrate my readiness to contribute as a data engineer by building secure, efficient, and data-driven solutions. This professional self-assessment serves as an introduction to the technical artifacts that follow and reflects my preparation to deliver value in modern, data-centric computing environments.

---

## Core Technical Competencies

- Data Structures and Algorithms (AVL Trees, Big-O Analysis)
- Software Engineering and Design Patterns (MVVM, OOP, Modular Design)
- Database Systems (MongoDB, SQL, Aggregation Pipelines)
- Data Analytics and Visualization (Python, pandas, matplotlib)
- Client-Server and Mobile Application Development
- Secure Coding and Data Protection Principles
- Technical Communication and Stakeholder Collaboration

---

## Portfolio Artifacts Overview

### CS360 Software Engineering and Design 

I included my CS360 Warehouse Inventory Management Application in my ePortfolio because it represents a major milestone in my development as a software engineer. While the original version of the project successfully met its functional requirements, it was built using a tightly coupled structure where the user interface, business logic, and data operations all existed within a single class. This design worked initially, but it also highlighted why tightly coupled systems are not preferred in professional software development. Tightly coupled code is harder to maintain, more difficult to test, and limits the ability to introduce new features without risking unintended side effects.
Through the enhancement process, I transitioned the application to MVVM architecture, which embraces loose coupling, the preferred method in modern software engineering. By separating the system into independent layers (Model, View, and ViewModel), each component can change or expand with minimal impact on other parts of the system. This shift taught me firsthand how loosely coupled designs improve flexibility, support long-term scalability, and make it significantly easier to debug or update functionality. Implementing a Repository layer and reactive data handling through LiveData reinforced how professional applications manage data flow cleanly and efficiently.


### CS300 Algorithms and Data Structures

In my CS 300 Data Structures and Algorithms project, originally created during the course to manage university courses and their prerequisites. The program was designed to load course information, organize it for efficient retrieval, and allow the user to search and display prerequisite relationships. I chose this artifact for my ePortfolio because it represents one of my strongest demonstrations of working directly with fundamental data structures, algorithmic thinking, and performance-based decision making. Key components that showcase these skills include my transition from a basic Binary Search Tree (BST) implementation to an enhanced AVL tree structure, which ensures balanced insertion, faster lookup times, and consistent performance even with larger datasets. This enhancement strengthened the artifact by replacing a linear-degrading structure with a self-balancing tree, improving efficiency and demonstrating my ability to apply algorithms to real-world data problems.

I met the course outcomes I originally planned to address, particularly the outcome related to applying data structures to solve computational problems and improving algorithmic efficiency. The enhancement allowed me to deepen my understanding of tree rotations, height-balancing logic, and the impact of algorithm choice on time complexity. As a result, my updated outcome-coverage plan now includes a stronger emphasis on evaluating trade-offs between alternative data structures and implementing self-balancing algorithms.

### CS340 Databases and Analytics

CS-340 Animal Shelter project, originally implemented a functional CRUD-based dashboard that allowed users to search, filter, create, update, and delete records in a MongoDB database of shelter animals. For this enhancement, I expanded the system to include a data mining and analytics component that provides insight into adoption trends. This included adding new analytical methods to the backend, implementing aggregation pipelines, and visualizing adoption patterns directly in the Jupyter Notebook.

I included this artifact in my ePortfolio because it represents a meaningful progression from basic software development toward creating data-driven systems. The original project demonstrated my foundational skills in Python programming, the Dash framework, and MongoDB interactions. However, the enhanced version goes further by showing my ability to integrate analytics, work with non-relational databases at a deeper level, and derive insights that support organizational decision-making. The new analytical components—such as the analyze_adoptions() and seasonal_adoption_trends() methods—highlight my skills in data wrangling, aggregation, visualization, and interpretation. By combining back-end data processing with front-end presentation, the artifact illustrates my capability to design full-stack solutions that transform raw data into actionable knowledge.

---
