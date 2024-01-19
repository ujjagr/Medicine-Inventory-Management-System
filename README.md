# Medicine Inventory Management System

Welcome to the Medicine Inventory Management System! This project is implemented in C and provides a simple system for managing medicine inventory, purchasing medicines, and generating bills.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Add Medicine](#add-medicine)
  - [Purchase Medicine](#purchase-medicine)
  - [Remove Medicine](#remove-medicine)
  - [Medicine Statistics](#medicine-statistics)

## Introduction

This project is a Medicine Inventory Management System implemented in C. It allows users to add medicines, purchase medicines, remove medicines, and view statistics related to the medicines.

## Features

- Add new medicines to the inventory.
- Purchase medicines and generate bills.
- Remove medicines from the inventory.
- Display statistics of the existing medicines.

## Getting Started

### Prerequisites

- C compiler (supporting C99 or later)

### Installation

1. Clone the repository to your local machine.

    ```bash
    git clone https://github.com/your-username/medicine-inventory.git
    ```

2. Compile the code using a C compiler.

    ```bash
    gcc medicine_inventory.c -o medicine_inventory
    ```

3. Run the executable.

    ```bash
    ./medicine_inventory
    ```

## Usage

### Add Medicine

- Add new medicines to the inventory by providing details such as ID, name, manufacturer, manufacturing date, expiry date, quantity, price, and type.

### Purchase Medicine

- Purchase medicines by entering the name and type of the medicine, along with the desired quantity. The system will update the inventory and generate a bill.

### Remove Medicine

- Remove medicines from the inventory by entering the name and type of the medicine.

### Medicine Statistics

- View statistics of the existing medicines, including ID, name, manufacturer, manufacturing date, expiry date, quantity, price, type, and total price.
