"BASICS--------------------------------------------------------------
set nocompatible
set tabstop=4		""TabSize of 4  
set shiftwidth=4 	""Indentation fo 4  
set softtabstop=4 	""Enabeling it will remplace tabs by spaces in insert mode 
set noexpandtab 	""Enabeling it will remplace tabs by spaces  
set noswapfile
set nobackup
set exrc 
set number
syntax enable
"--------------------------------------------------------------------

"WILDMENU FOR FUZZY FILE SEARCH--------------------------------------
filetype plugin on	"plugins(included with vim) for netrw
set path+=**

set wildmenu "Display all matching files when we tab complete
	" NOW WE CAN:
	" Type :find
	" - Hit tab to :find by partial match
	" - Use * to make it fuzzy
	" - Opened files will be buffered try it out
	" - :b lets you autocomplete any open buffer
"--------------------------------------------------------------------

"TAG JUMPING---------------------------------------------------------
" Create the `tags` file (need to install ctags first)
command! MakeTags !ctags -R .
	" NOW WE CAN:
	" - Use ^] to jump to tag under cursor
	" - Use g^] for ambiguous tags
	" - Use ^t to jump back up the tag stack
	" THINGS TO CONSIDER:
	" - This doesn't help if you want a visual list of tags
	" AUTOCOMPLETE:
	" The good stuff is documented in |ins-completion|
	" HIGHLIGHTS:
	" - ^x^n for JUST this file
	" - ^x^f for filenames (works with our path trick!)
	" - ^x^] for tags only
	" - ^n for anything specified by the 'complete' option
	" NOW WE CAN:
	" - Use ^n and ^p to go back and forth in the suggestion list
"--------------------------------------------------------------------

"FILE BROWSING-------------------------------------------------------
let g:netrw_banner=0        " disable annoying banner
let g:netrw_browse_split=4  " open in prior window
let g:netrw_altv=1          " open splits to the right
let g:netrw_liststyle=3     " tree view
let g:netrw_list_hide=netrw_gitignore#Hide()
let g:netrw_list_hide.=',\(^\|\s\s\)\zs\.\S\+'

	" NOW WE CAN:
	" - :edit a folder to open a file browser
	" - <CR>/v/t to open in an h-split/v-split/tab
	" - check |netrw-browse-maps| for more mappings
"--------------------------------------------------------------------

"SNIPPETS------------------------------------------------------------
" 	Command	 Read  template 		    move cursor 
nnoremap ,html :-1read $HOME/.vim/.skeleton.html<CR>3jwf>a

" NOW WE CAN:
" - Take over the world!
"   (with much fewer keystrokes)
"--------------------------------------------------------------------

"BUILD INTEGRATION---------------------------------------------------
" Steal Mr. Bradley's formatter & add it to our spec_helper
" http://philipbradley.net/rspec-into-vim-with-quickfix
" Configure the `make` command to run RSpec
set makeprg=bundle\ exec\ rspec\ -f\ QuickfixFormatter

	" NOW WE CAN:
	" - Run :make to run RSpec
	" - :cl to list errors
	" - :cc# to jump to error by number
	" - :cn and :cp to navigate forward and back
"--------------------------------------------------------------------

"REMAPS--------------------------------------------------------------
let mapleader=" " "leader is space
"Kepp The good habits no arrows for you
nnoremap <Left>:echo "No left for you!"<CR> 
nnoremap <Right>:echo "No right for you!"<CR> 
nnoremap <Up> :echo "No up for you!"<CR>
nnoremap <Down> :echo "No down for you!"<CR>
"Ease of window jumg intead of ^wj etc..
map <leader>h :wincmd h<CR> 
map <leader>j :wincmd j<CR>
map <leader>k :wincmd k<CR>
map <leader>l :wincmd l<CR>
"--------------------------------------------------------------------


