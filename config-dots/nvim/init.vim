:set nu
call plug#begin('~/.vim/plugged')
"Plug 'Shougo/deoplete.nvim'
"Plug 'deoplete-plugins/deoplete-clang'
Plug 'dense-analysis/ale'
"let g:deoplete#enable_at_startup = 1
 " call deoplete#custom#source('_', 'max_menu_width', 80)
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
let g:neoformat_enabled_cpp = ['clangformat']
let g:neoformat_enabled_c = ['clangformat']
