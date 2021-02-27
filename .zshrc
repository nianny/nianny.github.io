# If you come from bash you might have to change your $PATH.
export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="/home/nianny/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="af-magic"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to automatically update without prompting.
# DISABLE_UPDATE_PROMPT="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

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
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"


alias ll="ls -Gla"
alias mkdir="mkdir -pv"
# A bunch of git aliases
alias g="git"
alias gs="git status"
alias ga="git add"
alias gaa="git add -A"
alias gc="git commit"
alias gcm="git commit -m"
alias gca="git commit --amend --no-edit"
alias gl="git log --graph"
alias gls="git log --oneline"
alias gd="git diff"
alias gds="git diff --stat"
alias gb="git branch"
alias gpl="git pull"
alias gpsh="git push"
alias pdf="/mnt/c/Program\ Files\ \(x86\)/Adobe/Acrobat\ Reader\ DC/Reader/AcroRd32.exe"

# not an alias but incredibly useful
mkcd() {
    mkdir $1
    cd $1
}

cppbuild(){
    g++ -std=c++17 -o $1.exe $1.cpp
    ./$1.exe
}

cppbuild_spe(){
    g++ -std=c++11 -o $1.exe $2.cpp
}

cpprun(){
    ./$1
}

# opens github folder and 
opengit(){
    cd /mnt/d/Github
    ls
}

alias edge="/mnt/c/Program\ Files\ \(x86\)/Microsoft/Edge/Application/msedge.exe"
alias firefox="/mnt/c/Program\ Files/Firefox\ Nightly/firefox.exe"


home(){
    cd ~
}

down(){
    cd /mnt/d/downloads
}



cb_download(){
    curl -o $1 https://codebreaker-statements.s3-ap-southeast-1.amazonaws.com/$1
}


personal-dec(){
    cd /mnt/d/Github/Deccourse-Competitive-Programming/Nianhe_s\ stuff/
    ls
}

coco(){
    firefox https://coco.sgedushare.com/#/courselist//course/5e35896193bbcb16002f1784/24e5
}

powershell(){
    /mnt/c/Windows/System32/WindowsPowerShell/v1.0/powershell.exe
}

# newbash(){
#     /mnt/c/Program\ Files/Git/git-bash.exe
# }


opencpp(){
    vim $1.cpp
    cppbuild $1
}
sls(){
    firefox https://vle.learning.moe.edu.sg/
}
jap-20(){
    firefox https://vle.learning.moe.edu.sg/studentgroup/5bb5a53e-b011-48c5-b46b-5c85b9e61d
}

kf1(){
    firefox kf1karting.com
}

slgroup(){
    firefox https://vle.learning.moe.edu.sg/mygroups
}

japextra(){
    firefox http://watanoc.com/tag/n5/
    firefox https://tadoku.org/japanese/free-books/
    firefox https://japanesetest4you.com/category/jlpt-n5/jlpt-n5-listening-test/
    firefox https://a1.marugotoweb.jp/en/life_and_culture.php
    firefox https://www.erin.jpf.go.jp/en/
    firefox https://www.nhk.or.jp/lesson/en/
}


gitcommit(){
    git add .
    git commit -m $1
    git push
}


swiftpull(){
    cd /mnt/d/Github/Trying-out-swift/

    git pull
}

runpy(){
    vim $1.py
    py $1.py
}





checkcpp() {
    cppbuild_spe $2 $2
    < $1.in ./$2.exe | diff $1.out -
}


macbookpro () {
    ssh nianhexiao@nianhes-mbp
}

lessons () {
    cd /mnt/d/Desktop/Raffles\ Institution/Year\ 2/Lessons/
    ls
}


export PATH="/home/nianny/.pyenv/bin:$PATH"
eval "$(pyenv init -)"
eval "$(pyenv virtualenv-init -)"\

cs () {
    mkdir $1
    cd $1
    cp /mnt/d/Downloads/index.html index.html
    cp /mnt/d/Downloads/style.css style.css
    cp /mnt/d/Downloads/sketch.js sketch.js

    code sketch.js


    live-server

    
}

comp () {
    mkdir $1
    cd $1
    cp /mnt/d/Downloads/cpp.cpp main.cpp
    code main.cpp

    
}