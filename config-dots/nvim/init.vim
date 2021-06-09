:set nu
call plug#begin('~/.vim/plugged')
Plug  'dense-analysis/ale'
Plug  'arakashic/chromatica.nvim'
Plug  'frazrepo/vim-rainbow'
Plug  'jiangmiao/auto-pairs', { 'for' : ['c','f90']}
Plug 'ajmwagar/vim-deus'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
call plug#end()
let g:ale_linters = {
    \ 'python': ['pylint'],
    \ 'vim': ['vint'],
    \ 'cpp': ['clang'],
    \ 'c': ['clang']
\}
let g:neoformat_cpp_clangformat = {
    \ 'exe': 'clang-format',
    \ 'args': ['--style="{IndentWidth: 4}"']
\}
let g:deoplete#enable_at_startup = 1
let g:ale_echo_msg_error_str = 'E'
let g:ale_echo_msg_warning_str = 'W'
let g:ale_echo_msg_format = '[%linter%] %s [%severity%]'
let g:neoformat_enabled_cpp = ['clangformat']
let g:neoformat_enabled_c = ['clangformat']
let g:rainbow_active = 1
let g:rainbow_ctermfgs = ['green', 'yellow', 'red', 'darkblue']
inoremap <A> <ESC> 
colorscheme deus
set tabstop=4
set softtabstop=0 noexpandtab
set shiftwidth=4
syntax on
let g:airline_theme='deus'
