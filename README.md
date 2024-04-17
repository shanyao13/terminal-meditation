# terminal-meditation
Focus Trataka meditation triggered from your terminal. Runs in Opengl

Includes 90-second timer, which will automatically close the program once the timer expires (will add ability to specify length of meditation session from cli when I have time to update this again)


![image](https://github.com/Andrew-Pynch/terminal-meditation/assets/43330642/4242114f-01a3-4a70-8278-d52a3b03a01d)
## Trataka Explained + [Guided Trataka with Doctor K](https://www.youtube.com/watch?v=snt1i5_1uhY)
Trataka as I understand it (I am quite new to the practice) is a form of meditation aimed towards enhancing the practitioners abilities of focus. Terminal-meditation has become an extremely useful tool for my personal use right before beginning a bout of focused work. 


# usage

## clone
```
git clone https://github.com/Andrew-Pynch/terminal-meditation && cd-terminal-meditation
```

## install deps
install opengl

```
sudo apt-get install libgl1-mesa-dev
```

install FreeGLUT
linux

```
sudo apt-get install freeglut3-dev
```

osx

```
brew install freeglut
```

install GLEW
linux

```
sudo apt-get install libglew-dev
```

osx

```
brew install glew
```

## install meditation
make sure you have cmake setup then just run make
```
make
```

move the binary into usr/bin so you can run from anywhere
```
chmod +x install.sh && sudo ./install.sh
```

## enjoy!
```
meditate
```

# sources

Got the Sri Yantra w/correct colours from [Wikipedia](https://en.wikipedia.org/wiki/Yantra)
