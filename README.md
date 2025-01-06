# Clothing Store Delivery and Inventory System

This project implements a **Clothing Store Delivery and Inventory Management System** using C++. The system supports a variety of operations such as browsing inventory, managing sales, calculating delivery charges, and maintaining order information. It uses algorithms like **Dijkstra's** and **Prim's** to calculate delivery distances and optimize routing.
---

## Features

### 1. **Interactive Menu**
- Provides options to browse sections for men, women, and kids.
- Allows viewing items in `New Arrivals` and `Sales` sections.
- Includes guidance for new customers.

### 2. **Delivery Management**
- Supports inter-city and intra-city deliveries.
- Calculates delivery charges based on distances using Dijkstra's and Prim's algorithms.
- Provides estimated delivery time based on distance.

### 3. **Inventory and Sales**
- Displays detailed item catalogs for various categories:
  - **Women**: Unstitched, stitched, and accessories.
  - **Men**: Casual, formal, and traditional wear.
  - **Kids**: Clothing, shoes, and accessories.
- Offers discounts (30% and 50%) on selected items.
- Calculates total costs including GST.

### 4. **Order Management**
- Maintains a linked list of orders for efficient tracking.
- Clones orders with details such as delivery distance and charges.
- Provides a final receipt with itemized costs.

---

## Algorithms Used

### 1. **Dijkstra's Algorithm**
- Calculates the shortest path for inter-city deliveries.
- Ensures efficient delivery routing between major cities.

### 2. **Prim's Algorithm**
- Optimizes intra-city delivery routes by calculating the Minimum Spanning Tree (MST).
- Minimizes additional travel distances.

---

## Code Structure

### Key Classes
1. **`order`**:
   - Manages individual orders including item details, cost, and delivery distance.

2. **`receipt`**:
   - Handles receipt generation and total cost calculation, including GST.

3. **`delivery`**:
   - Implements delivery management using Dijkstra's and Prim's algorithms.

4. **`NewArrival`, `sale`, and `menu`**:
   - Manage inventory display, sales, and customer interactions.

5. **`userchoice`**:
   - Centralizes user navigation, menu selections, and overall functionality.

---

## How to Run the Program

### 1. Clone the Repository
`git clone https://github.com/CashierLess-Clothing-Store.git`
### 2. Navigate to the directory
`cd CashierLess-Clothing-Store`
### 3. Compile the Code
`g++ -o ClothingStore main.cpp`

### 4.  Run the Program
`./ClothingStore`

# Project Highlights

### Scalable Codebase:
- Modular design for easy addition of new features.
- Separate classes for distinct functionalities.
  
### Real-World Application:
- Implements algorithms for delivery optimization.
- Simulates inventory and sales systems used in retail businesses.
  
### User-Friendly:
- Interactive menus for easy navigation.
- Clear guidance for new customers.

# Future Enhancements

### Database Integration:
- Add a database backend for persistent order tracking.
  
### GUI Implementation:
- Create a graphical user interface to improve user experience.
  
### International Deliveries:
- Extend delivery management to include international locations.
  
### Multi-Store Support:
- Add functionality to manage multiple store branches.

# Contribution Guidelines
### Contributions are welcome! If you'd like to contribute:

- Fork the repository.
- Create a feature branch.
- Submit a pull request.
- Please ensure your code follows the project's coding standards.

