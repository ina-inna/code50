pip install pyfiglet

from pyfiglet import Figlet

figlet = Figlet()
figlet.getFonts()

if len(sys.argv) == 0:
        text = input ("Input: ")
        print()
elif len(sys.argv) == 2:


else:
         sys.exit("Incorrect usage")