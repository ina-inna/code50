from pyfiglet import Figlet

figlet = Figlet()
figlet.getFonts()
figlet.setFont(font=sys.argv[1])


if len(sys.argv) == 0:
        text = input ("Input: ")
        print(figlet.renderText(text))

else:
         sys.exit("Invalid usage")