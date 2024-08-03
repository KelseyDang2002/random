import csv

file = r"C:\Users\Kelsey PC\Downloads\cars.csv"

fields = []
rows = []

def program_exit():
    print(f"\n\nProgram exiting...")
    print("Goodbye.")
    exit(0)

def dataset_read():
    with open(file, "r") as csvfile:
        csvreader = csv.reader(csvfile)
        fields = next(csvreader)

        for row in csvreader:
            rows.append(row)

        print("Total no. of rows: %d" % (csvreader.line_num))

    print("Fields: " + ", ".join(field for field in fields))
    print("\n")

def display_dataset(n):
    for row in rows[:n]:
        for col in row:
            print("%s" % col, end="")

if __name__ == "__main__":
    dataset_read()
    display_dataset(1)