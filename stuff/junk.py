import webbrowser
import time

def help_menu():
    print("\nHelp Menu:")
    print("\t- Enter CTRL + C to exit program.")

def open_url(domain):
    full_url = 'www.' + domain
    print(f"Opening {full_url}")
    webbrowser.open_new_tab(full_url)
    print("Opened.")

help_menu()

while True:
    try:
        domain = input("\nEnter a domain name (example.gov): ")
        open_url(domain)

    except KeyboardInterrupt:
        print("\n\nProgram exited.")
        # time.sleep(1)
        break