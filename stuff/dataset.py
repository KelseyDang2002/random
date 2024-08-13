import csv

DIMENSIONS_HEIGHT = 0
DIMENSIONS_LENGTH = 1
DIMENSIONS_WIDTH = 2
ENGINE_INFORMATION_DRIVELINE = 3
ENGINE_INFORMATION_ENGINETYPE = 4
ENGINE_INFORMATION_HYBRID = 5
ENGINE_INFORMATION_GEARS = 6
ENGINE_INFORMATION_TRANSMISSION = 7
FUEL_INFORMATION_CITYMPG = 8
FUEL_INFORMATION_FUELTYPE = 9
FUEL_INFORMATION_HIGHWAYMPG = 10
IDENTIFICATION_CLASSIFICATION = 11
IDENTIFICATION_ID = 12
IDENTIFICATION_MAKE = 13
IDENTIFICATION_MODELYEAR = 14
IDENTIFICATION_YEAR = 15
ENGINE_STATISTICS_HORSEPOWER = 16
ENGINE_STATISTICS_TORQUE = 17

INDEX_START = 0
DATA_START = 1

file = r"C:\Users\Kelsey PC\Downloads\cars.csv"

def program_exit(message):
    print(f"\n\n\n{message} -> Program exiting...")
    print("Goodbye.")
    exit(0)

def menu():
    print("\n\n_________________ MENU __________________")
    print("|\t\t\t\t\t|")
    print("|\t1. Display vehicles\t\t|")
    print("|\t2. Get vehicle make & model\t|")
    print("|\t3. Exit program\t\t\t|")
    print("|\t\t\t\t\t|")
    print("_________________________________________\n")

def dataset_read():
    rowList = []
    with open(file) as csvFile:
        csvReader = csv.reader(csvFile, delimiter=",")
        for row in csvReader:
            rowList.append(row)
        print(f"Total no. of rows: {csvReader.line_num}")

    print(f"Total no. of columns: {len(rowList[0])}\n")
    print(f"Fields: {rowList[0]}")
    print("_________________________________________\n")
    return rowList

def display_rows(rowList, rowNumber):
    for index, row in enumerate(rowList[DATA_START:rowNumber + 1], INDEX_START + 1):
        if rowNumber < DATA_START or rowNumber > len(rowList):
            print("Invalid input.")
            break
    
        print(f"\n{index}. {row[IDENTIFICATION_ID]}:")
        print(f"{row}")

def display_all_makes():
    # unique makes
    print("")

def display_all_models(make):
    # unique models
    print("")

def get_vehicle_make_model(rowList, make, model):
    for index, row in enumerate(rowList, INDEX_START):
        if (make == row[IDENTIFICATION_MAKE].upper() and model in row[IDENTIFICATION_MODELYEAR].upper()):
            print(f"\n{index}. {row[IDENTIFICATION_ID]}")
            print(f"\tEngine: {row[ENGINE_INFORMATION_ENGINETYPE]}")
            print(f"\tTransmission: {row[ENGINE_INFORMATION_TRANSMISSION]}")
            print(f"\tDrivetrain: {row[ENGINE_INFORMATION_DRIVELINE]}")

def main():
    choice = int(input("> Enter a menu option (1-3): "))
    match choice:
        case 1:
            rowNumber = int(input("\n> Enter desired number of rows: "))
            display_rows(rowList, rowNumber)
        
        case 2:
            # display_all_makes()
            make = input("\n> Enter a vehicle make: ").upper()
            # display_all_models()
            model = input("> Enter vehicle model (Press 'enter' if unspecified): ").upper()
            get_vehicle_make_model(rowList, make, model)

        case 3:
            program_exit("Exit program")

        case _:
            print("\nInvalid input. Try again.")

if __name__ == "__main__":
    while True:
        try:
            menu()
            rowList = dataset_read()
            main()

        except KeyboardInterrupt:
            program_exit("KeyboardInterrupt")