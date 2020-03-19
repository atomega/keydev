#bin/usr/bash

sudo apt-get install -y build-essential cmake python3-dev
sudo apt-get install -y vim-youcompleteme
#git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
python3 ~/.vim/bundle/youcompleteme/install.py --clang-completer
