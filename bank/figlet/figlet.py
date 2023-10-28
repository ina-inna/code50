import sys

from pyfiglet import Figlet

figlet = Figlet()
fonts = figlet.getFonts()


if len(sys.argv) == 1:
        text = input ("Input: ")
        figlet.setFont(font=random(fonts))
        print(figlet.renderText(text))
elif len(sys.argv) == 3:
        if sys.argv[0] != "-f" or "--font" and sys.argv[1] in list:
                sys.exit("Invalid usage")
        else:
                text = input ("Input: ")
                figlet.setFont(font=sys.argv[1])
                print(figlet.renderText(text))

else:
        sys.exit("Invalid usage")
