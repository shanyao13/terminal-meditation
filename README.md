# terminal-meditation
![image](https://github.com/Andrew-Pynch/terminal-meditation/assets/43330642/4242114f-01a3-4a70-8278-d52a3b03a01d)
## Trataka Explained
[Guided Trataka with Doctor K](https://www.youtube.com/watch?v=snt1i5_1uhY)


Focus Trataka meditation triggered from your terminal. Runs in Opengl

Includes 90 second timer, will automatically close once timer expires

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
