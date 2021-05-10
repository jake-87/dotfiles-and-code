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
# alias ohmyzsh="mate ~/.oh-my-zsh"
alias pint="doas pkg install -y"
alias nano="nvim"
if test -z "${XDG_RUNTIME_DIR}"; then export XDG_RUNTIME_DIR=/tmp/${UID}-runtime-dir
	if ! test -d "${XDG_RUNTIME_DIR}"; then
		mkdir "${XDG_RUNTIME_DIR}"
		chmod 0700 "${XDG_RUNTIME_DIR}"
	fi
fi
alias bfetch="pfetch | sed \"s/3843/1048576/g\" | sed \"s/2.67/6.12/g\" | sed \"s/Core(TM) i5 CPU M 480/Threadripper 8950 CPU (256) /g\" | sed \"s/FreeBSD 13.0/FreeBSD 19.5/g\" "
alias la="ls -lah"
# ,theme.sh brogrammer
alias init="doas init"
alias cpm="cc -Wall -pipe -march=native -O2 -lm -lcurses"
alias csm="cc -Oz -s -ffast-math -m32 -march=x86-64 -fno-exceptions -ffunction-sections -fdata-sections"
export PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin:/home/freebsd/bin:/home/freebsd/.cargo/bin:/usr/local/lib/qt5/bin/qmake
alias csmcpp="clang++ -Oz -s -ffast-math -m32 -march=x86-64 -fno-exceptions -ffunction-sections -fdata-sections"
export QMAKESPEC=freebsd-clang
alias vim=nvim
alias vi=nvim
alias ,chmodhelp="ls -lah $HOME/coding/chmod-tests/"
# ,donut &
alias ,upgrade="doas pkg update && doas pkg upgrade && pfetch"
alias ,clone-src-current="doas git clone https://git.freebsd.org/src.git /usr/src"
export EDITOR=nvim
alias ,nightly=",upgrade && doas ,auto-backup && cd /usr/src && doas git pull && echo \"When you want too, cd to /usr/src and run \",building-inc\" to know how to build the lastest kernel and world.\""
alias ",building-inc"="echo \"cd /usr/src, make -j5 buildworld, make -j5 kernel, reboot to new kernel, cd /usr/src again, make -j5 installworld, mergemaster -Ui, done.\""
alias back=-
markdownview() { markdown "$1" | lynx -stdin; }
alias wahoo=echo "Mario time!"
alias gitinfo="onefetch"
alias hx=hexyl
export LD_LIBRARY_PATH=/usr/local/include/:${LD_LIBRARY_PATH}
