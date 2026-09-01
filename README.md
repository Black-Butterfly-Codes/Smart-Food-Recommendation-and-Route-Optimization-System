<div align="center">

# 🍽️ SMART FOOD RECOMMENDATION SYSTEM

### 🚗 Smart Takeaway • 🍽️ Smart Dine-In • 🛵 Smart Delivery

**A C++ Data Structures & Algorithms Project**

<br>


\

</div>

---

## 🌟 About The Project

The **Smart Food Recommendation and Route Optimization System** is a C++ project that combines **Data Structures, Algorithms, Route Optimization, Restaurant Recommendation, Time Management, and User Preferences**.

This is not just a traditional food-ordering system. Its main purpose is to recommend the most suitable restaurant according to the user's current situation instead of simply selecting the nearest restaurant.

The system is built around three intelligent modules:

* 🚗 **Smart Takeaway**
* 🍽️ **Smart Dine-In**
* 🛵 **Smart Delivery**

> 🍽️ **Smart Recommendations Based on Distance + Rating + Travel Time + Preparation Time + User Preferences**

---

## 🎯 Project Objectives

The project aims to:

* Recommend restaurants intelligently using multiple factors.
* Calculate the shortest route between locations.
* Match travel time with food preparation time.
* Consider cuisine preferences and previous orders.
* Distribute users across restaurants using congestion information.
* Manage users, menus, carts, payments, and order history.
* Demonstrate practical applications of C++ Data Structures and Algorithms.

---

## ✨ Key Features

### 🔐 User Account Management

When the system starts, users can choose:

```text
========================================
       WELCOME TO XYZ FOOD SYSTEM
========================================

1. New User
2. Existing User
3. Exit
```

#### New User Registration

* 👤 Username creation
* 🔑 Password creation
* 🚫 Duplicate username prevention
* 🛡️ Password strength checking
* ✅ Account creation confirmation

#### Password Strength Checking

The system evaluates:

* Password length
* Uppercase letters
* Lowercase letters
* Numbers
* Special characters

Possible results:

```text
🔴 WEAK PASSWORD
Please create a stronger password.
```

```text
🟡 MODERATE PASSWORD

1. Create a New Password
2. Continue Anyway
```

```text
🟢 STRONG PASSWORD
Account Created Successfully!
```

#### Existing User Login

```text
Enter Username:
Enter Password:
```

After successful verification:

```text
Login Successful!
Welcome back, Username!
```

---

## 🏠 Main Menu

After registration or login, the user enters the main menu:

```text
========================================
              MAIN MENU
========================================

1. Smart Takeaway
2. Smart Dine-In
3. Smart Delivery
4. Order History
5. Feedback
6. Logout
```

The first three options are the core recommendation modules.

---

## 🚗 Smart Takeaway

Smart Takeaway is one of the most unique features of the project.

The system does not simply find the nearest restaurant. Instead, it recommends a restaurant based on:

* 📍 Current location
* 🗺️ User's route
* 🎯 Destination
* 🍕 Cuisine preference
* ⏱️ Travel time
* 🍳 Food preparation time
* ⭐ Restaurant rating
* ❤️ Previous user preferences

### Step 1: Select Current Location

The user selects a predefined location:

```text
1. College
2. Clock Tower
3. ISBT
4. Rajpur Road
5. Prem Nagar
6. Ballupur
```

This project uses a simulated map and does not require real GPS.

### Step 2: Select Journey Type

```text
Are you travelling somewhere?

1. Yes, I am travelling
2. No, I will pick up the food and return
```

### Travelling User

If the user is travelling, the system asks for the destination:

```text
Current Location: College
Destination: Clock Tower
```

The system then calculates the route:

```text
College → Clock Tower
```

### Step 3: Select Cuisine

```text
Choose Cuisine:

1. Indian
2. Chinese
3. Italian
4. Fast Food
5. Continental
```

### Step 4: Find Matching Restaurants

The system filters restaurants in stages:

```text
All Restaurants
        ↓
Restaurants Serving Selected Cuisine
        ↓
Restaurants Located On or Near the Route
        ↓
Calculate Travel Time
        ↓
Calculate Food Preparation Time
        ↓
Rank Restaurants
```

Example:

| Restaurant   | Cuisine | Travel Time | Preparation Time | Rating |
| ------------ | ------- | ----------: | ---------------: | -----: |
| Restaurant A | Italian |   5 minutes |       15 minutes |    4.5 |
| Restaurant B | Italian |  13 minutes |       15 minutes |    4.7 |
| Restaurant C | Italian |  28 minutes |       15 minutes |    4.8 |

### Smart Time Matching

The system calculates:

```text
Time Difference = |Travel Time - Preparation Time|
```

Example:

```text
Restaurant A:
Travel Time = 5 minutes
Preparation Time = 15 minutes
Difference = 10 minutes
```

```text
Restaurant B:
Travel Time = 13 minutes
Preparation Time = 15 minutes
Difference = 2 minutes
```

Restaurant B is a better option because the user's arrival time closely matches the food preparation time.

### Recommended Result

```text
========================================
       BEST SMART TAKEAWAY OPTION
========================================

Restaurant: Restaurant B
Cuisine: Italian
Distance: 2.5 km
Estimated Arrival: 13 minutes
Estimated Preparation: 15 minutes
Rating: 4.7

Reason:
Your arrival time closely matches the food preparation time.
```

### Non-Travelling User

If the user is returning after pickup, the system asks:

```text
How far are you willing to travel?

1. Within 2 km
2. Within 5 km
3. Within 10 km
```

Restaurants are then ranked using:

1. Distance
2. Rating
3. Preparation time
4. Cuisine preference
5. User history

---

## 🍽️ Smart Dine-In

Smart Dine-In recommends restaurants based on:

* 🍛 Cuisine preference
* 📍 Distance
* ⏰ Available time
* ⭐ Restaurant rating
* 📊 Restaurant congestion
* 🧾 Current orders
* 🏪 Restaurant capacity

### Step 1: Select Cuisine

```text
What would you like to eat?

1. Indian
2. Chinese
3. Italian
4. Fast Food
5. Continental
```

### Step 2: Select Ordering Method

```text
How would you like to proceed?

1. Go to the restaurant and order there
2. Select a restaurant and pre-order
```

### Option A: Visit and Order There

The user selects a maximum travel range:

```text
How far are you willing to travel?

1. 2 km
2. 5 km
3. 10 km
```

Example result:

```text
Restaurants Available:

1. Spice Garden
   Distance: 1.2 km
   Rating: 4.5

2. Food Palace
   Distance: 3.1 km
   Rating: 4.6

3. Royal Kitchen
   Distance: 6.5 km
   Rating: 4.8
```

### Option B: Pre-Order for Dine-In

The user selects a time window:

```text
When do you plan to dine?

1. Within 1 hour
2. Within 2 hours
3. Within 3 hours
4. Within 4 hours
5. More than 4 hours
```

### Smart Time-Window Logic

The recommendation changes according to the user's available time.

* A user with a one-hour window receives nearby recommendations.
* A user with a three-hour window can be recommended a slightly farther restaurant.
* A user with a longer time window has more flexibility.

### Congestion Distribution

The system avoids recommending the same highly-rated restaurant to every user.

Example:

| Restaurant   | Distance | Rating | Current Load |
| ------------ | -------: | -----: | ------------ |
| Restaurant A |     1 km |    4.8 | High         |
| Restaurant B |     2 km |    4.7 | Low          |
| Restaurant C |     3 km |    4.6 | Low          |

The recommendation considers:

```text
Distance + Rating + Time Window + Restaurant Capacity + Current Orders
```

This helps distribute users across restaurants and gives lower scores to restaurants with very large pending queues.

---

## 🛵 Smart Delivery

Smart Delivery recommends restaurants based on:

* ⭐ Rating
* 📍 Distance
* 🍳 Preparation time
* 🛵 Estimated delivery time
* ❤️ User preferences
* 📊 Restaurant load

> **The nearest restaurant is not always the best restaurant.**

### Step 1: Select Cuisine

```text
Choose Cuisine:

1. Indian
2. Chinese
3. Italian
4. Fast Food
5. Continental
```

### Step 2: Select Search Range

```text
Search Restaurants Within:

1. 1 km
2. 2 km
3. 5 km
4. 10 km
```

### Example Restaurant List

| Restaurant   | Distance | Rating |
| ------------ | -------: | -----: |
| Restaurant A |     1 km |    2.5 |
| Restaurant B |   1.5 km |    4.8 |
| Restaurant C |     2 km |    4.9 |
| Restaurant D |     3 km |    3.1 |

Restaurant A may not be recommended despite being closest because of its low rating.

### Recommendation Levels

```text
🟢 BEST
High rating + short distance + suitable preparation time
```

```text
🟡 ACCEPTABLE
Good rating + moderate distance
```

```text
🔴 NOT RECOMMENDED
Low rating or very long travel time
```

The system primarily displays the best and acceptable options. Poor options are shown only when the user selects:

```text
Show All Restaurants
```

### Restaurant Selection

```text
1. Choose Recommended Restaurant
2. View All Restaurants
3. Select Manually
```

---

## 🍔 Menu and Food Selection

After selecting a restaurant, the user can view its menu:

```text
MENU

1. Butter Chicken
2. Paneer Tikka
3. Biryani
4. Naan
```

The user can add one or more items to the cart.

---

## 🛒 Shopping Cart

Users can:

```text
1. Add Food
2. Remove Food
3. View Cart
4. Confirm Order
```

A linked list can be used to represent the cart:

```text
Butter Chicken
       │
       ▼
Paneer Tikka
       │
       ▼
Naan
       │
       ▼
NULL
```

A linked list demonstrates:

* Insertion
* Deletion
* Traversal
* Searching

---

## 💳 Payment System

Payment is simulated for academic purposes.

Available options:

```text
1. Cash
2. Online Payment
```

No real payment gateway is required.

### Order Confirmation

```text
========================================
          ORDER CONFIRMED
========================================

Restaurant: XYZ Food
Food: Pizza
Payment: Online
Estimated Pickup/Delivery Time: 15 minutes

Thank you for using XYZ Food!
```

---

## 📜 Order History

Every completed order is stored for the user.

Example:

```text
========================================
             ORDER HISTORY
========================================

Order #101
Restaurant: Spice Garden
Cuisine: Indian
Total: ₹450

Order #102
Restaurant: Pizza House
Cuisine: Italian
Total: ₹650
```

Order history can be used for:

* Recommending frequently ordered restaurants
* Tracking previous purchases
* Personalizing future recommendations

---

## 🔁 Frequently Ordered Restaurant Logic

The system tracks how often a user orders from each restaurant.

Example:

```text
Spice Garden → 10 orders
Pizza House  → 5 orders
Dragon Wok   → 2 orders
```

If two restaurants have similar ratings and distances, the system may recommend the restaurant the user frequently orders from.

```text
Recommended for You: Spice Garden

Reason:
You frequently order from this restaurant.
```

Previous preference should not override:

* Very low rating
* Excessive distance
* Very long preparation time
* High congestion

---

## ⭐ Feedback System

Before logout or exit, the system can ask:

```text
Would you like to give feedback?

1. Yes
2. No
```

If the user selects yes:

```text
Rate your experience: 1 to 5
Enter Feedback:
```

Feedback can be stored for future analysis and improvement.

---

## 🧠 Recommendation Engine

The recommendation engine combines all relevant information and calculates a score for each restaurant.

General formula:

```text
Restaurant Score =
Rating Score
+ Distance Score
+ Preparation Time Match
+ User Preference Score
- Congestion Penalty
```

A simplified formula can be used in the initial implementation:

```text
Score =
(Rating × Rating Weight)
- (Distance × Distance Weight)
- Preparation Time Difference
+ Preference Bonus
- Congestion Penalty
```

Different modules use different priorities.

### Takeaway Score Priority

1. Restaurant is on or near the route
2. Travel time
3. Preparation time match
4. Rating
5. User preference

### Dine-In Score Priority

1. User time window
2. Distance
3. Rating
4. Restaurant congestion
5. Cuisine availability

### Delivery Score Priority

1. Rating
2. Distance
3. Delivery time
4. Preparation time
5. User preference

---

## 🗺️ Route Optimization

The system uses a weighted graph to represent the simulated map.

```text
Location → Vertex
Road     → Edge
Distance → Weight
```

Example:

```text
        College
        /      \
      2 km     3 km
      /          \
Clock Tower --- ISBT
      \          /
       \        /
       Rajpur Road
```

The graph represents:

* Locations
* Roads
* Distances
* Restaurant routes
* User-to-restaurant paths

### Adjacency List

```cpp
vector<vector<pair<int, int>>> graph;
```

The adjacency list stores each location and its connected locations with distances.

An adjacency list is suitable because road networks usually do not connect every location directly.

### Shortest Path Flow

```text
User Location
      │
      ▼
Find Restaurant
      │
      ▼
Calculate Shortest Route
      │
      ▼
Estimate Travel Time
```

---

## 🧠 Data Structures Used

| Data Structure     | Purpose                                 |
| ------------------ | --------------------------------------- |
| 🌐 Graph           | Represent locations and roads           |
| 🗺️ Adjacency List | Store connected locations               |
| ⚡ Hash Table       | Fast user and restaurant lookup         |
| 🔺 Priority Queue  | Process shortest paths                  |
| 📋 Queue           | Manage restaurant orders                |
| 🔗 Linked List     | Shopping cart and order records         |
| 📦 Vector          | Store restaurants, menus, and locations |
| 📚 Stack           | Optional navigation history             |

---

## ⚙️ Algorithms Used

### Dijkstra's Algorithm

Used for:

* Shortest route calculation
* Shortest distance calculation
* Estimated travel time
* User-to-restaurant route planning

With a priority queue:

```text
Time Complexity: O((V + E) log V)
```

Where:

* `V` = Number of vertices
* `E` = Number of edges

### Priority Queue

Used inside Dijkstra's Algorithm.

The closest location receives the highest priority.

```text
Shortest Distance
        ↓
Highest Priority
```

### Hash Table / `unordered_map`

Used for:

* User account lookup
* Duplicate username checking
* Restaurant lookup
* Cuisine indexing

Example:

```cpp
unordered_map<string, User> users;
```

Average complexity:

```text
Search: O(1)
Insert: O(1)
```

### Linear Search

Used for:

* Searching food items
* Searching small menus
* Searching unsorted data

Complexity:

```text
O(n)
```

### Binary Search

Used for:

* Searching sorted restaurants
* Searching by rating
* Searching within a distance range

Binary search requires sorted data.

Complexity:

```text
O(log n)
```

### Merge Sort

Used for sorting restaurants by:

* Rating
* Distance
* Preparation time
* Recommendation score

Complexity:

```text
O(n log n)
```

### Custom Restaurant Ranking

Restaurants can be ranked using a custom comparator.

Example delivery priority:

```text
1. Rating
2. Distance
3. Preparation Time
4. User Preference
```

---

## 📋 Order Queue and Congestion Logic

Each restaurant can maintain a queue of pending orders:

```text
ORDER 1
   ↓
ORDER 2
   ↓
ORDER 3
   ↓
ORDER 4
```

Orders are processed using FIFO logic:

```text
First In → First Out
```

The number of pending orders can be used in the dine-in recommendation system.

```text
Higher Pending Orders
        ↓
Higher Congestion
        ↓
Lower Recommendation Score
```

This makes the congestion feature technically meaningful.

---

## 🔐 User Data Structure

Users can be stored using a hash table:

```text
Username
    ↓
Hash Function
    ↓
User Information
```

Example:

```cpp
unordered_map<string, User> users;
```

Average complexity:

| Operation                | Complexity |
| ------------------------ | ---------: |
| Find User                |       O(1) |
| Add User                 |       O(1) |
| Check Duplicate Username |       O(1) |

---

## 🧩 C++ Class Design

The project can be organized using the following classes:

```text
User
Restaurant
FoodItem
Order
Graph
RecommendationEngine
FoodSystem
```

### User

```text
User
├── username
├── password
├── orderHistory
└── preferences
```

### Restaurant

```text
Restaurant
├── id
├── name
├── location
├── cuisines
├── rating
├── preparationTime
└── orderQueue
```

### FoodItem

```text
FoodItem
├── id
├── name
├── cuisine
├── price
└── preparationTime
```

### Order

```text
Order
├── orderID
├── restaurant
├── items
├── paymentMethod
└── orderStatus
```

---

## 🏗️ Object-Oriented Programming Concepts

### Encapsulation

Data and related functions are kept together inside classes.

```text
Restaurant
├── Private Data
└── Public Functions
```

### Constructors

Constructors initialize objects.

```cpp
Restaurant restaurant(...);
```

### Inheritance

Inheritance can optionally be used for different order types:

```text
Order
├── TakeawayOrder
├── DineInOrder
└── DeliveryOrder
```

### Polymorphism

Different order types can implement their own estimated-time calculations:

```text
Takeaway Order → User travel time
Delivery Order → Delivery route time
Dine-In Order  → Reservation/time window
```

Inheritance and polymorphism are optional but can strengthen the C++ implementation.

---

## 📊 Data Structure and C++ Mapping

| Feature                  | Data Structure / Algorithm | C++ Concept      |
| ------------------------ | -------------------------- | ---------------- |
| User Login               | Hash Table                 | Classes          |
| Password Check           | String Processing          | Functions        |
| Duplicate Username       | Hashing                    | STL              |
| Locations                | Graph                      | Classes          |
| Roads                    | Weighted Edges             | Structs/Classes  |
| Shortest Route           | Dijkstra                   | Priority Queue   |
| Restaurant Storage       | Vector                     | STL              |
| Food Search              | Linear Search              | Functions        |
| Sorted Restaurant Search | Binary Search              | Algorithms       |
| Restaurant Ranking       | Merge Sort                 | Recursion        |
| Shopping Cart            | Linked List                | Pointers/Classes |
| Order Processing         | Queue                      | FIFO             |
| Order History            | Linked List/Vector         | Classes          |
| Navigation               | Stack                      | STL              |
| Different Order Types    | Inheritance                | Polymorphism     |
| Time Calculation         | Algorithms                 | Functions        |

---

## 🔁 Complete User Flow

```text
START
  │
  ▼
WELCOME
  │
  ├── New User
  │       │
  │       ▼
  │   Create Account
  │       │
  │       ▼
  │   Password Check
  │       │
  │   ┌───┼──────────────┐
  │   │   │              │
  │ Weak  Moderate      Strong
  │   │   │              │
  │ Recreate  Continue/  Enter
  │           Recreate   System
  │
  └── Existing User
          │
          ▼
        LOGIN
          │
          ▼
      MAIN MENU
          │
    ┌─────┼─────────────┐
    ▼     ▼             ▼
TAKEAWAY DINE-IN     DELIVERY
    │     │             │
    ▼     ▼             ▼
Route +  Cuisine +   Cuisine +
Cuisine  Time Window Range
    │     │             │
    ▼     ▼             ▼
Smart Restaurant Recommendation
    │     │             │
    ▼     ▼             ▼
Select   Visit/       Select
Food     Pre-Order    Food
    │     │             │
    ▼     │             ▼
Payment  │           Payment
    │     │             │
    └─────┼─────────────┘
          ▼
     CONFIRMATION
          │
          ▼
     ORDER HISTORY
          │
          ▼
       MAIN MENU
          │
    ┌─────┴─────┐
    ▼           ▼
 LOGOUT       EXIT
    │           │
    ▼           ▼
 FEEDBACK      END
```

---

## 🏗️ Project Structure

```text
Smart-Food-Recommendation-System/
│
├── 📁 src/
│   ├── main.cpp
│   ├── User.cpp
│   ├── Restaurant.cpp
│   ├── FoodItem.cpp
│   ├── Order.cpp
│   ├── Graph.cpp
│   ├── RecommendationEngine.cpp
│   └── FoodSystem.cpp
│
├── 📁 include/
│   ├── User.h
│   ├── Restaurant.h
│   ├── FoodItem.h
│   ├── Order.h
│   ├── Graph.h
│   ├── RecommendationEngine.h
│   └── FoodSystem.h
│
├── 📁 data/
│   ├── users.txt
│   ├── restaurants.txt
│   ├── menu.txt
│   └── orders.txt
│
├── 📁 docs/
│   └── project-notes.md
│
└── 📄 README.md
```

---

## 🛠️ Technologies Used

<div align="center">

| Technology         | Usage                                                             |
| ------------------ | ----------------------------------------------------------------- |
| 💻 C++             | Main programming language                                         |
| 🧠 Data Structures | Core project implementation                                       |
| ⚙️ Algorithms      | Searching, sorting, routing, and ranking                          |
| 🏗️ OOP            | Classes, objects, and encapsulation                               |
| 📚 STL             | `vector`, `unordered_map`, `queue`, `priority_queue`, and `stack` |
| 🗺️ Graph Theory   | Route optimization                                                |
| 📁 File Handling   | Data persistence                                                  |
| 🔁 Recursion       | Merge sort and algorithmic operations                             |

</div>

---

## 🎯 What Makes This Project Different?

### 🚗 Smart Takeaway Timing

The restaurant is selected by comparing:

```text
User Arrival Time
        VS
Food Preparation Time
```

The goal is to reduce waiting time and improve pickup efficiency.

### 🍽️ Smart Dine-In Time Windows

Recommendations change according to:

```text
Available Time + Distance + Rating + Restaurant Load
```

This allows the system to recommend restaurants that fit the user's schedule.

### 🛵 Smart Delivery Recommendations

The system does not blindly choose the nearest restaurant. It balances:

```text
Rating + Distance + Preparation Time + Delivery Time
```

### 🧠 Personalized Recommendations

The system can consider:

* Previous preferences
* Frequently ordered restaurants
* Restaurant quality
* Distance
* Preparation time
* Current congestion

---

## ⚠️ Project Scope

This project uses a simulated environment with predefined data.

```text
✅ Predefined Locations
✅ Predefined Roads
✅ Simulated Restaurant Data
✅ Cuisine Information
✅ Restaurant Ratings
✅ Food Preparation Times
✅ Estimated Travel Times
✅ Simulated Payments
✅ Simulated Order Processing

❌ Real-Time GPS
❌ Live Traffic Data
❌ Real Restaurant APIs
❌ Real Payment Gateway
❌ Live Delivery Tracking
```

The project does not claim to use real-time GPS, traffic, or restaurant data unless those features are implemented in a future version.

---

## 🚀 Future Improvements

* 🗺️ Real-time GPS integration
* 🚦 Live traffic updates
* 🏪 Real restaurant database
* 🖥️ Graphical User Interface
* 🌐 Web application
* 📱 Mobile application
* 🤖 AI-based recommendations
* 📍 Real-time order tracking
* ☁️ Cloud database
* 💳 Secure online payment integration
* 📊 Advanced analytics and reporting
* 🔔 Order status notifications

---

## 📚 Core Technical Requirements

### Data Structures

* Graph
* Adjacency List
* Hash Table
* Priority Queue
* Queue
* Linked List
* Vector/Array
* Optional Stack

### Algorithms

* Dijkstra's Shortest Path Algorithm
* Merge Sort
* Binary Search
* Linear Search
* Custom Restaurant Ranking Algorithm
* Password Strength Evaluation
* Congestion-Based Recommendation

### C++ Concepts

* Classes and Objects
* Encapsulation
* Constructors
* Functions
* File Handling
* STL
* Recursion
* Optional Inheritance
* Optional Polymorphism

If manual implementation is required, the following structures can be implemented without relying entirely on STL:

* Custom Linked List
* Custom Queue
* Custom Graph
* Manual Merge Sort
* Manual Binary Search

---

## 👨‍💻 Author

<div align="center">

### 🦋 Nimish Sharma

**🔗 ****[Visit My GitHub Profile](https://github.com/Black-Butterfly-Codes)**

</div>

---

<div align="center">

### ⭐ If you like this project, consider giving it a star!

**Made with ❤️ and C++**

<br>

🦋 **Black Butterfly Codes**

</div>
