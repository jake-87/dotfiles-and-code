export ZSH="/home/freebsd/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="minimal"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
if test -z "${XDG_RUNTIME_DIR}"; then export XDG_RUNTIME_DIR=/tmp/${UID}-runtime-dir
	if ! test -d "${XDG_RUNTIME_DIR}"; then
		mkdir "${XDG_RUNTIME_DIR}"
		chmod 0700 "${XDG_RUNTIME_DIR}"
	fi
fi
alias la="ls -lah"
alias init="doas init"
export PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin:/home/freebsd/bin:/home/freebsd/.cargo/bin:/usr/local/lib/qt5/bin/qmake
export QMAKESPEC=freebsd-clang
export EDITOR=nvim
export VISUAL=nvim
alias back=-
alias gitinfo="onefetch"
alias hx=hexyl
OMP_NUM_THREADS=4
export OMP_NUM_THREADS
alias htop="bashtop"
export PATH=$PATH:$HOME/.local/bin
export LD_LIBRARY_PATH=/usr/local/include/:${LD_LIBRARY_PATH}
alias cmatrix="cmatrix -C cyan"
alias cp="cp -v"
alias mv="mv -v"
alias head="sed 11q" # see http://harmful.cat-v.org/software/
alias rg="ranger"
alias feh="nomacs"
fortune
alias fex="find . | grep -v git | xargs grep"
alias c="clear"
alias pkgup="doas pkg update && doas pkg upgrade && doas pkg autoremove"
