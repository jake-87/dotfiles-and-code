:set nu
call plug#begin('~/.vim/plugged')
Plug  'Shougo/deoplete.nvim'
Plug  'deoplete-plugins/deoplete-clang'
Plug  'dense-analysis/ale'
Plug  'arakashic/chromatica.nvim'
Plug  'frazrepo/vim-rainbow'
Plug  'jiangmiao/auto-pairs', { 'for' : 'c' }
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
let g:ale_echo_msg_error_str = 'E'
let g:ale_echo_msg_warning_str = 'W'
let g:ale_echo_msg_format = '[%linter%] %s [%severity%]'
let g:neoformat_enabled_cpp = ['clangformat']
let g:neoformat_enabled_c = ['clangformat']
let g:rainbow_active = 1
let g:rainbow_ctermfgs = ['green', 'yellow', 'red', 'darkblue']
