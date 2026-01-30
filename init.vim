set number
set relativenumber
set showmatch
set hlsearch
set clipboard=unnamedplus
set autoindent
set tabstop=8               
set softtabstop=8           
set expandtab               
set shiftwidth=8
set splitright

syntax on

let mapleader=" "
command! -nargs=0 CopileRun :w | execute '!g++ -o a ' . expand('%') . '&& ./a < in ' 

tnoremap <Esc> <C-\><C-n> "exit mode insert in :term
nnoremap <C-n> :vsplit in<CR>:vertical resize 40<CR>
nnoremap <Leader>cp :w! $HOME/GOIC/copi.cpp <CR> 
map <F4> :CopileRun <CR>



colorscheme unokai
