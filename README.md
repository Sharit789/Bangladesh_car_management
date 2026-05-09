# Car Management System 🚗🇧🇩

A complete **C++ Car Management System** designed with a **Bangladesh-style vehicle database** using `struct`, `vector`, loops, and functions.

This project simulates **300 realistic car records** including owner details, vehicle condition, mileage, chassis numbers, BRTA fitness certificates, pricing, accident history, and more.

---

# 📌 Features

- Uses `struct Car`
- Stores **300 car objects**
- Uses `vector<Car>`
- Bangladesh-style:
  - Owner names
  - Chassis numbers
  - BRTA fitness certificate numbers
  - Import years
  - Vehicle conditions
- Detailed car reports
- Full summary table
- Search cars by model
- Summary statistics
- Clean formatted terminal output

---

# 🛠 Technologies Used

- C++
- Standard Template Library (STL)
- `vector`
- `iomanip`
- `string`
- `sstream`

---

# 📂 Project Structure

```bash
bangladesh_car_management.cpp
README.md
```

---

# 🚘 Data Included

Each car contains:

- Owner Name
- Car Model
- Car Price
- Registration Cost
- Insurance Cost
- Fuel Cost
- Maintenance Cost
- Mileage
- Chassis Number
- Engine Number
- Fitness Certificate Number
- Import Year
- AC Condition
- Brake Condition
- Steering Condition
- Tire Condition
- Battery Condition
- Accident History
- Flood Damage
- Service History
- Resale Value
- Spare Parts Availability
- Smoke Condition
- Oil Leakage
- Rust Condition

---

# 🇧🇩 Bangladesh Realistic Dataset

The program uses realistic Bangladesh-oriented vehicle information such as:

### Popular Models

- Toyota Premio
- Toyota Axio
- Honda Grace
- Nissan X-Trail
- Toyota Allion

### Sample BRTA-style Fitness Number

```text
BRTA/DHAKA/2022/102345
```

### Sample Chassis Number

```text
BD-PRMO-1002345
```

---

# 📋 Program Output

The program displays:

## 1. Detailed View

Detailed information for first 5 cars.

## 2. Full Car List

Displays all 300 cars in table format including:

- Price
- Mileage
- Import Year
- AC Condition
- Brake Condition
- Smoke Condition
- Rust Condition
- Accident History

## 3. Summary Statistics

Displays:

- Total fleet value
- Total resale value
- Flood-damaged cars
- Accident history count
- Oil leakage count
- AC condition breakdown

## 4. Search Feature

Example:

```cpp
searchByModel(cars, "Toyota Premio");
```

---

# ▶️ How to Compile & Run

## Using g++

Compile:

```bash
g++ bangladesh_car_management.cpp -o car_system
```

Run:

```bash
./car_system
```

---

# 💡 Learning Concepts Used

This project demonstrates:

- Structures (`struct`)
- Vectors (`vector<Car>`)
- Functions
- Loops
- String formatting
- Data simulation
- Table formatting
- Realistic dataset generation

---

# 🎯 Educational Purpose

This project is useful for:

- C++ beginners
- OOP preparation
- Data structure practice
- University assignments
- Portfolio projects
- Console application development

---

# 📈 Future Improvements

Possible upgrades:

- File handling
- Save/load database
- Sorting by price or mileage
- GUI version
- Login system
- Database integration
- Search by chassis number
- Filter accident-free cars

---

# 👨‍💻 Author

Developed for practice and educational purposes using C++.

---

# ⭐ GitHub Tips

If you upload this project to GitHub:

- Add screenshots
- Add sample output
- Add license
- Add `.gitignore`
- Use meaningful commits

Example:

```bash
git commit -m "Added Bangladesh car management system"
```

---

# 📜 License

This project is free to use for educational purposes.
