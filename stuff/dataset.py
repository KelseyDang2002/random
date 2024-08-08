import csv

file = r"C:\Users\Kelsey PC\Downloads\cars.csv"


def program_exit(message):
    print(f"\n\n\n{message} -> Program exiting...")
    print("Goodbye.")
    exit(0)

def user_input():
    rowNumber = int(input("\nEnter number of rows: "))
    print("")
    return rowNumber

def dataset_read():
    rows = []
    with open(file) as csvFile:
        csvReader = csv.reader(csvFile, delimiter=",")

        for row in csvReader:
            rows.append(row)

        print("Total no. of rows: %d" % (csvReader.line_num))

    print("Columns:\n", rows[0])

    return rows

def get_rows(rows, n):
    for row in rows[1:n + 1]:
        print(row, "\n")

if __name__ == "__main__":
    rows = dataset_read()
    rowNumber = user_input()
    get_rows(rows, rowNumber)