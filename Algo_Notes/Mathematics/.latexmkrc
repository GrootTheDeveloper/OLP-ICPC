# Enable shell-escape for minted; run biber for biblatex
$pdflatex = 'pdflatex -interaction=nonstopmode -shell-escape %O %S';
$lualatex = 'lualatex -interaction=nonstopmode -shell-escape %O %S';
$xelatex  = 'xelatex  -interaction=nonstopmode -shell-escape %O %S';

add_cus_dep('glo', 'gls', 0, 'makeglossaries');

$biber = 'biber %O %B';
$pdf_mode = 1; # Build PDF
$bibtex_use = 2; # Use biber by default for biblatex
$aux_dir = 'latex.out';
$out_dir = 'latex.out';
