set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set colorcolumn=110
highlight ColorColumn ctermbg=darkgray
augroup project
    autocmd!
    autocmd BufRead,BufNewFile *.h,*.c set filetype=c
augroup END
let &path.="src/include,/usr/include/AL,"
nnoremap <F4> :make!<cr>
nnoremap <F6> :make! d<cr>
nnoremap  <F5> :!./a<cr>
" For local replace
nnoremap gr gd[{V%::s/<C-R>///gc<left><left><left>
" For global replace
nnoremap gR gD:%s/<C-R>///gc<left><left><left>
"set makeprg=make\ -C\ ../build\ -j9
set ai 
set cin
set showmatch
set hlsearch
set incsearch
set ignorecase
if !has('gui_running')
set mouse=
endif
set pastetoggle=<F2>
set number
syntax on
set scrolloff=3
let g:ycm_confirm_extra_conf = 0
