# Author: Mcube728
# This is a simple script that interfaces with the mealDB api, and displays various recipes. 

import json
import requests
import ssl

api_key = "1"
base_url = "https://www.themealdb.com/api/json/v1/1/"

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

def search_meal_by_name(base_url):
    recipe = input("Enter the name of the recipe you want to search for: ")
    url = base_url + "search.php?s=" + recipe
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_meal = JSON_data["meals"]
    number = 20
    n = 0
    ingredients = list()
    while n < number:
        if JSON_meal[0]["strMeasure"+str(n+1)] is None: JSON_meal[0]["strMeasure"+str(n+1)] = " "
        if JSON_meal[0]["strIngredient"+str(n+1)] is None: JSON_meal[0]["strIngredient"+str(n+1)] = " "
        s = JSON_meal[0]["strMeasure"+str(n+1)] + " " + JSON_meal[0]["strIngredient"+str(n+1)]
        if s == " ":
            n += 1
            continue 
        elif s.isspace():
            n += 1
            continue
        else:
            ingredients.append(s)
            n += 1
            continue
        print(n)
    print("================================")
    print("Meal ID: ", JSON_meal[0]["idMeal"])
    print("Meal Name: ", JSON_meal[0]["strMeal"])
    print("Meal category(Veg/Non. Veg): ", JSON_meal[0]["strCategory"])
    print("Area of origination: ", JSON_meal[0]["strArea"])
    print("Ingredients: ",  end=" ")
    for n in ingredients:
        print(n,",", end=" ")
    print("\n\nInstructions: ", JSON_meal[0]["strInstructions"])
    print("-------------------------------------------------------------------------------------\n")

def list_meals_by_first_letter(base_url):
    letter = input("Enter the first letter you want to search recipes with(Please be careful, as this is case sensitive): ")
    url = base_url + "search.php?f=" + letter
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_meal = JSON_data["meals"]
    length = len(JSON_meal)
    start_index = 0
    print("=== Recipes that start with",letter,": ===")
    for index in range(length):
        print(JSON_meal[index]["strMeal"])
    print("-------------------------------------------------------------------------------------\n")

def lookup_meal_by_ID(base_url):
    meal_ID = input("Enter the ID of the recipe you want to search for: ")
    url = base_url + "lookup.php?i=" + meal_ID
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_meal = JSON_data["meals"]
    number = 20
    n = 0
    ingredients = list()
    while n < number:
        if JSON_meal[0]["strMeasure"+str(n+1)] is None: JSON_meal[0]["strMeasure"+str(n+1)] = " "
        if JSON_meal[0]["strIngredient"+str(n+1)] is None: JSON_meal[0]["strIngredient"+str(n+1)] = " "
        s = JSON_meal[0]["strMeasure"+str(n+1)] + " " + JSON_meal[0]["strIngredient"+str(n+1)]
        if s == " ":
            n += 1
            continue
        elif s.isspace():
            n += 1
            continue
        else:
            ingredients.append(s)
            n += 1
            continue
        print(n)
    print("================================")
    print("Meal ID: ", JSON_meal[0]["idMeal"])
    print("Meal Name: ", JSON_meal[0]["strMeal"])
    print("Meal category(Veg/Non. Veg): ", JSON_meal[0]["strCategory"])
    print("Area of origination: ", JSON_meal[0]["strArea"])
    print("Ingredients: ",  end=" ")
    for n in ingredients:
        print(n,",", end=" ")
    print("\n\nInstructions: ", JSON_meal[0]["strInstructions"])
    print("-------------------------------------------------------------------------------------\n")

def random_meal(base_url):
    print("Displaying a random meal......... ")
    url = base_url + "random.php"
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_meal = JSON_data["meals"]
    number = 20
    n = 0
    ingredients = list()
    while n < number:
        if JSON_meal[0]["strMeasure"+str(n+1)] is None: JSON_meal[0]["strMeasure"+str(n+1)] = " "
        if JSON_meal[0]["strIngredient"+str(n+1)] is None: JSON_meal[0]["strIngredient"+str(n+1)] = " "
        s = JSON_meal[0]["strMeasure"+str(n+1)] + " " + JSON_meal[0]["strIngredient"+str(n+1)]
        if s == " ":
            n += 1
            continue
        elif s.isspace():
            n += 1
            continue
        else:
            ingredients.append(s)
            n += 1
            continue
        print(n)
    print("================================")
    print("Meal ID: ", JSON_meal[0]["idMeal"])
    print("Meal Name: ", JSON_meal[0]["strMeal"])
    print("Meal category(Veg/Non. Veg): ", JSON_meal[0]["strCategory"])
    print("Area of origination: ", JSON_meal[0]["strArea"])
    print("Ingredients: ",  end=" ")
    for n in ingredients:
        print(n,",", end=" ")
    print("\n\nInstructions: ", JSON_meal[0]["strInstructions"])
    print("-------------------------------------------------------------------------------------\n")

def meal_categories(base_url):
    print("Displaying meal categories......... ")
    url = base_url + "categories.php"
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_category = JSON_data["categories"]
    n = 0
    print("========== CATEGORIES ==========")
    for n in range(len(JSON_category)):
        print(JSON_category[n]["idCategory"] + ". " + JSON_category[n]["strCategory"])
        print("Description:", JSON_category[n]["strCategoryDescription"])
        print("----------------------------------------\n")
    print("-------------------------------------------------------------------------------------\n")

def meal_areas(base_url):
    print("Displaying meal categories......... ")
    url = base_url + "list.php?a=list"
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_areas = JSON_data["meals"]
    n = 0
    print("========== AREAS OF ORIGIN OF RECIPES ==========")
    for n in range(len(JSON_areas)):
        number = str(n + 1)
        print(number + ". " + JSON_areas[n]["strArea"])
    print("-------------------------------------------------------------------------------------\n")

def meal_ingredients(base_url):
    print("Displaying meal ingredients......... ")
    url = base_url + "list.php?i=list"
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_ingredients = JSON_data["meals"]
    n = 0
    print("========== INGREDIENTS USED IN THE RECIPES ==========")
    for n in range(len(JSON_ingredients)):
        print(JSON_ingredients[n]["idIngredient"] + ". " + JSON_ingredients[n]["strIngredient"])
        print("Description:", JSON_ingredients[n]["strDescription"])
        print("----------------------------------------\n")
    print("-------------------------------------------------------------------------------------\n")

def filter_meal_by_ingredient(base_url):
    q = input("Enter the ingredient you want to filter recipes by: ")
    query = q.lower()
    Q_list = list(query) 
    for index in range(len(Q_list)):
        if Q_list[index].isspace():
            Q_list[index]="_"
    query = "".join(Q_list)  
    url = base_url + "filter.php?i=" + query
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_meal = JSON_data["meals"]
    n = 0
    print("========== MEALS FILTERED BY QUERIED INGREDIENT ==========")
    for n in range(len(JSON_meal)):
        n1=str(n+1)
        print(n1+".")
        print("Meal ID: ", JSON_meal[n]["idMeal"])
        print("Meal Name: ", JSON_meal[n]["strMeal"])
        print("-------------------------------\n")
    print("-------------------------------------------------------------------------------------\n")

def filter_meal_by_category(base_url):
    q = input("Enter the category you want to filter recipes by: ")
    query = q.lower()
    Q_list = list(query) 
    for index in range(len(Q_list)):
        if Q_list[index].isspace():
            Q_list[index]="_"
    query = "".join(Q_list)  
    url = base_url + "filter.php?c=" + query
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_meal = JSON_data["meals"]
    n = 0
    print("========== MEALS FILTERED BY QUERIED CATEGORY ==========")
    for n in range(len(JSON_meal)):
        n1=str(n+1)
        print(n1+".")
        print("Meal ID: ", JSON_meal[n]["idMeal"])
        print("Meal Name: ", JSON_meal[n]["strMeal"])
        print("-------------------------------\n")
    print("-------------------------------------------------------------------------------------\n")

def filter_meal_by_area(base_url):
    q = input("Enter the area you want to filter recipes by: ")
    query = q.lower()
    Q_list = list(query) 
    for index in range(len(Q_list)):
        if Q_list[index].isspace():
            Q_list[index]="_"
    query = "".join(Q_list)  
    url = base_url + "filter.php?a=" + query
    print("Retrieving", url, "..........")
    r = requests.get(url)
    JSON_data = r.json()
    JSON_meal = JSON_data["meals"]
    n = 0
    print("========== MEALS FILTERED BY QUERIED CATEGORY ==========")
    for n in range(len(JSON_meal)):
        n1=str(n+1)
        print(n1+".")
        print("Meal ID: ", JSON_meal[n]["idMeal"])
        print("Meal Name: ", JSON_meal[n]["strMeal"])
        print("-------------------------------\n")
    print("-------------------------------------------------------------------------------------\n")

print("Hello!!!")
while True:
    print("What do you want to do?")
    print("""
1. Search a meal by name.
2. List meals by their first letter.
3. Lookup meal by ID.
4. Lookup a single random meal. 
5. List all meal categories.
6. List of all the Categories the recipes in the database.
7. List of all the Areas of Origin of recipes. 
8. List of all the Ingredients used in the recipes in this database. 
9. Filter meals by Main Ingredients.
10. Filter meals by Categories.
11. Filter meals by Area of Origin.
12. Exit
    """)
    choice = int(input("Enter your choice here: "))
    if choice == 12:    break
    elif choice == 1:   search_meal_by_name(base_url)
    elif choice == 2:   list_meals_by_first_letter(base_url)
    elif choice == 3:   lookup_meal_by_ID(base_url)
    elif choice == 4:   random_meal(base_url)
    elif choice == 5:   meal_categories(base_url)
    elif choice == 6:   meal_categories(base_url)
    elif choice == 7:   meal_areas(base_url)
    elif choice == 8:   meal_ingredients(base_url)
    elif choice == 9:   filter_meal_by_ingredient(base_url)
    elif choice == 10:  filter_meal_by_category(base_url)
    elif choice == 11:  filter_meal_by_area(base_url)
    else: print("ERROR!!!")