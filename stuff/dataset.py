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
    print("|_______________________________________|\n")
    return

def dataset_read():
    rowList = []
    with open(file) as csvFile:
        csvReader = csv.reader(csvFile, delimiter=",")
        for row in csvReader:
            rowList.append(row)
        print(f"Total no. of rows: {csvReader.line_num}")

    print(f"Total no. of columns: {len(rowList[0])}\n")
    print(f"Attributes:")
    for index, attr in enumerate(rowList[0], INDEX_START):
        print(f"[{index}]\t{attr}")
    
    print("_________________________________________", end="")
    print("_________________________________________\n")
    return rowList

def display_rows(rowList, rowNumber):
    for index, row in enumerate(rowList[DATA_START:rowNumber + 1], INDEX_START + 1):
        if rowNumber < DATA_START or rowNumber > len(rowList):
            print("Invalid input.")
            break
    
        print(f"\n{index}. {row[IDENTIFICATION_ID]}:")
        print(f"{row}")

    return

def get_all_makes(rowList):
    makeList = []
    for row in rowList[DATA_START:]:
        if row[IDENTIFICATION_MAKE] not in makeList:
            makeList.append(row[IDENTIFICATION_MAKE])
    
    print("\nMakes:\n")
    makeList.sort()
    for index, make in enumerate(makeList, INDEX_START + 1):
        print(f"{make}", end=" | ")
        if index % 4 == 0:
            print("\n------------------------------------------------------")

    return

def get_all_models(rowList, make):
    modelList = []
    for row in rowList:
        modelNoYearSublist = row[IDENTIFICATION_MODELYEAR].split(" ")[2:]
        modelNoYearStr = " ".join(modelNoYearSublist)
        
        if (make == row[IDENTIFICATION_MAKE].upper()) and (modelNoYearStr not in modelList):
            modelList.append(modelNoYearStr)
            
    print(f"\n{make} models:\n")
    for model in modelList:
        print(f"{model}")

    return

def get_vehicle_info(rowList, make, model):
    print(f"\nResults for {make} {model}:")
    for index, row in enumerate(rowList, INDEX_START):
        if (make == row[IDENTIFICATION_MAKE].upper()) and (model in row[IDENTIFICATION_MODELYEAR].upper()):
            print(f"\n{index}. {row[IDENTIFICATION_ID]}")
            print(f"\t- Engine: {row[ENGINE_INFORMATION_ENGINETYPE]}")
            print(f"\t- Transmission: {row[ENGINE_INFORMATION_TRANSMISSION]}")
            print(f"\t- Drivetrain: {row[ENGINE_INFORMATION_DRIVELINE]}")
            print(f"\t- MPG (City): {row[FUEL_INFORMATION_CITYMPG]} miles")
            print(f"\t- MPG (Highway): {row[FUEL_INFORMATION_HIGHWAYMPG]} miles")

    return

def main():
    choice = int(input("> Enter a menu option (1-3): "))
    match choice:
        case 1:
            rowNumber = int(input("\n> Enter desired number of rows: "))
            display_rows(rowList, rowNumber)
            input("\n> Press 'enter' to continue...")
        
        case 2:
            get_all_makes(rowList)
            make = input("\n\n> Enter a vehicle make: ").upper()
            get_all_models(rowList, make)
            model = input("\n> Enter vehicle model (Press 'enter' if unspecified): ").upper()
            get_vehicle_info(rowList, make, model)
            input("\n> Press 'enter' to continue...")

        case 3:
            program_exit("Exit program")

        case _:
            print("\nInvalid input. Try again.")

    return

if __name__ == "__main__":
    while True:
        try:
            menu()
            rowList = dataset_read()
            main()

        except KeyboardInterrupt:
            program_exit("KeyboardInterrupt")