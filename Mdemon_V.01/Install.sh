clear
DIR="`pwd`"
BIN="/usr/local/bin"
LOCAL="/usr/share/MaxwellDemon"
LAUNCHER="/home/$USER/.local/share/applications"

echo "------------------"
echo "Loading Files..."
echo "------------------"
sudo mkdir $LOCAL

sudo cp -r DEMON1.png $LOCAL
sudo cp -r include/ $LOCAL
sudo cp -r src/ $LOCAL
sudo cp -r Imagenes/ $LOCAL
sudo cp -r Demon.cxx $LOCAL
sudo cp -r Demondef.h $LOCAL

echo "Create local files"

rootcling -f DemonDict.cxx -c include/Headers.h include/HeaderGui.h include/HeaderValues.h Demondef.h

g++ -o MaxwellDemon Demon.cxx DemonDict.cxx `root-config --glibs --cflags --libs`
sudo cp -r DemonDict_rdict.pcm $LOCAL

#sudo ln -s ~/Desktop/Exe/MaxwellDemon /usr/bin/MaxwellDemon
echo "------------------"
echo "Installing..."
echo "------------------"

echo "------------------"
echo "Installation was succesful "
sudo cp -r $DIR/MaxwellDemon $LOCAL/MaxwellDemon
#sudo ln -s ~/Desktop/Exe/MaxwellDemon /usr/bin/MaxwellDemon

sudo ln -d -s -f $LOCAL/MaxwellDemon $BIN/MaxwellDemon
echo $LAUNCHER
#sudo cp $DIR/files/MaxwellDemon.desktop $LAUNCHER
#sudo cp $DIR/files/MaxwellDemon.desktop /usr/share/applications
sudo cp $DIR/files/MaxwellDemon.desktop /home/$USER/Desktop
#Add Permissions

sudo chmod ugo+xwr -R $LOCAL
sudo chmod -R u+xwr $BIN/MaxwellDemon
#####
#sudo chmod a+xwr $LAUNCHER/MaxwellDemon.desktop
###########
#sudo chmod -R a+xwr /usr/share/applications/MaxwellDemon.desktop
sudo chmod -R a+xwr /home/$USER/Desktop/MaxwellDemon.desktop

MaxwellDemon

