:set nu
call plug#begin('~/.vim/plugged')
Plug  'Shougo/deoplete.nvim'
Plug  'deoplete-plugins/deoplete-clang'
Plug  'dense-analysis/ale'
Plug  'arakashic/chromatica.nvim'
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
