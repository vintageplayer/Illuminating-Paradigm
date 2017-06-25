#!/bin/sh
dpkg-query -l libglui2c2 >> /dev/null
if [ $? -ne 0 ]
then
	echo "Installing glui library..." 
	sudo dpkg -i libglui2c2_2.36-4ubuntu1_amd64.deb
fi
dpkg-query -l libglui-dev >> /dev/null
if [ $? -ne 0 ]
then
	echo "Installing glui development files..."
	sudo dpkg -i libglui-dev_2.36-4ubuntu1_amd64.deb
fi

g++ nav.cpp -o main 1>> /dev/null
g++ test1.cpp -o nav -lglut -lglui 1>> /dev/null
g++ about.cpp -o about -lglui -lglut 1>> /dev/null
g++ example5.cpp -o work -lGL -lGLU -lglut -lglui 1>> /dev/null
echo "Done installing. Run \"main\" to execute program"
