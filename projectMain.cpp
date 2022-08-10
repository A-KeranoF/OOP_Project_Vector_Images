#include <iostream>
#include "Image.h"

void commandCheck(std::string arg, bool& check);
Image* createImage();
Shape* defaultCreate(const Type& type); // just in case; for testing

int main() {

	bool projectClosed = false;
	std::string command;

	std::cout << "Enter valid command. Type help to print list of known commands." << std::endl;

	do {
		std::cout << "Enter command: ";
		std::cin >> command;
		std::cout << std::endl;
		commandCheck(command, projectClosed);
		std::cout << std::endl;
	} while (!projectClosed);

	return 0;
}

void commandCheck(std::string arg, bool& exit) {

	if (arg == "help")
	{
		std::cout
				// this is pseudo command writing, since it is not written in one line
			<< "(Important! First use the command name, then enter arguments!)" << std::endl
			<< " (in development) new - create new image " << std::endl // make it so it has mostly only one instance open (singleton)
			<< " (in development) open <file> - open an image " << std::endl
			<< " (in development) close - close current file " << std::endl
			<< " exit - close the program" << std::endl
			<< " (in development) save - save current file " << std::endl
			<< " (in development) save as <format>" << std::endl
			<< " (in development) create <type> <components> - add shape " << std::endl
			<< " (in development) print - print the shapes in the image " << std::endl
			<< " (in development) bring forward <id> <layers> " << std::endl 
			<< " (in development) send backward <id> <layers> " << std::endl
			<< " (in development) group <region>" << std::endl
			<< " (in development) ungroup " << std::endl
			<< " (in development) translate <ids> <+x> <+y>    - move targets   (leave <ids> empty to apply to all shapes)" << std::endl
			<< " (in development) scale <ids> <length> <width> - scale targets  (leave <ids> empty to apply to all shapes)" << std::endl
			<< " (in development) rotate <ids> <degree>        - rotate targets (leave <ids> empty to apply to all shapes)" << std::endl;
	}
	else if (arg == "exit")
	{
		//if an image is open, ask for saving, then close it
		//delete image
		exit = true;
	}
	else if (arg == "new")
	{
		//check if another one is still open
		//createImage();	
		// i do not know how to make it that this image interracts with the commands
	}
	else if (arg == "open")
	{
		//check if another one is still open
	}
	else if (arg == "close")
	{
		std::cout << "Save image before closing? [Y/N] ";
		char answer = 'Y';
		do {
			std::cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				/*if (image is a file)
				{
					//image.save();
				}
				else
				{
					//"enter format"
					//image.saveAs(format);
				}*/
				break;
			}
			else if (answer == 'n' || answer == 'N')
			{
				std::cout << " closing ...";
				break;
			}
		} while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

		//delete image;
	}
	else if (arg == "save")
	{
		// if(image is file)
		// this image.save();
		// else image.saveAs();
	}
	else if (arg == "save as")
	{
		// enter format
		// this image.saveAs(format)
	}
	// !! from here on check if the image or file is open and in good contidion to read
	else if (arg == "create")
	{
		// enter type and components
		// factory create obj
		// image.addShape(obj);
	}
	else if (arg == "print")
	{
		//check if open
		//image.print();
	}
	else if (arg == "bring forward")
	{
		std::cout << "Enter shape ID: " << std::endl;
		int id = 0;
		std::cin >> id;
		std::cout << "How many layers?" << std::endl;
		int layers = 0;
		std::cin >> layers;

		//image.bringForward(id, layers);
	}
	else if (arg == "send backward")
	{
		std::cout << "Enter shape ID: " << std::endl;
		int id = 0;
		std::cin >> id;
		std::cout << "How many layers?" << std::endl;
		int layers = 0;
		std::cin >> layers;

		//image.sendBackward(id, layers);
	}
	else if (arg == "group")
	{
		//region
	}
	else if (arg == "ungroup")
	{
		//image.ungroup();
	}
	else if (arg == "translate")
	{
		std::cout << "Enter vertical change: ";
		int v = 0;
		std::cin >> v;
		std::cout << "Enter horisontal change: ";
		int h = 0;
		std::cin >> h;

		// image.translate(ids, v, h)
		// OR, if id is empty:
		// image.translate(v, h)
	}
	else if (arg == "scale")
	{
		std::cout << "Enter 1st coefficient: ";
		int c1 = 0;
		std::cin >> c1;
		std::cout << "Enter 2nd coefficient: ";
		int c2 = 0;
		std::cin >> c2;

		// image.scale(ids, c1, c2)
		// OR, if id is empty: //!! make it check the ID
		// image.scale(c1, c2)
	}
	else if (arg == "rotate")
	{
		std::cout << "Enter degrees: ";
		int degrees = 0;
		std::cin >> degrees;

		// image.rotate(ids, degrees)
		// OR, if id is empty: //!! make it check the ID
		// image.scale(degrees)
	}
	else
	{
		std::cout << "Invalid/unknown command" << std::endl;
	}
}

Image* createImage() {
	return new Image();
}

Shape* defaultCreate(const Type& t)
{
	switch (t)
	{
	case Type::CIRCLE:
		return new Circle();
	case Type::LINE:
		return new Line();
	case Type::POLYGON:
		return new Polygon();
	case Type::RECTANGLE:
		return new Rectangle();
	default:
		break;
	}
}