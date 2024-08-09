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

INDEX_START = 1

file = r"C:\Users\Kelsey PC\Downloads\cars.csv"

def program_exit(message):
    print(f"\n\n\n{message} -> Program exiting...")
    print("Goodbye.")
    exit(0)

def user_input():
    rowNumber = int(input("Enter desired number of rows: "))
    return rowNumber

def dataset_read():
    rowList = []
    with open(file) as csvFile:
        csvReader = csv.reader(csvFile, delimiter=",")
        for row in csvReader:
            rowList.append(row)
        print(f"Total no. of rows: {csvReader.line_num}")

    print(f"Total no. of Columns: {len(rowList[0])}\n")
    print(f"Fields: {rowList[0]}\n")
    return rowList

def menu():
    print("")

def display_rows(rowList, rowNumber):
    for index, row in enumerate(rowList[1:rowNumber + 1], INDEX_START):
        print(f"\n{index}. {row[IDENTIFICATION_ID]}:")
        print(f"{row}")

if __name__ == "__main__":
    rowList = dataset_read()
    rowNumber = user_input()
    display_rows(rowList, rowNumber)