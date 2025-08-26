# LaTeX OOP-style Template (Vietnamese)

Phần tiền xử lý `tex/preamble.tex`, từng chương ở `sections/`, hình ở `figures/`, tài liệu tham khảo ở `refs/references.bib`, bìa riêng ở `tex/titlepage.tex`.

## Cấu trúc
```
latex-oop-template/
├─ main.tex
├─ tex/
│  ├─ preamble.tex
│  └─ titlepage.tex
├─ sections/
│  ├─ 01-gioi-thieu.tex
│  └─ 02-ly-thuyet.tex
├─ refs/
│  └─ references.bib
├─ figures/
│  └─ .gitkeep
├─ .latexmkrc
├─ Makefile
└─ .gitignore
```

## Biên dịch
Yêu cầu:
- TeX Live đầy đủ (có các gói: `biblatex` (backend biber), `minted`, `tikz`, `enumitem`, `tocloft`, ...)
- Python + Pygments (để `minted` hoạt động)
- Trình biên dịch: `latexmk`, `biber`

### Cách 1: latexmk
```bash
latexmk -pdf main.tex
```
> Lưu ý: `minted` cần `-shell-escape`. File `.latexmkrc` đã bật cờ này.

### Cách 2: Makefile
```bash
make
# hoặc
make clean
```

## Ghi chú
- Thay đổi tiêu đề/tác giả trong `main.tex` hoặc `tex/titlepage.tex`.
- Thêm/chỉnh sửa mục lục chương bằng cách thêm `\input{sections/<file>.tex}` vào `main.tex`.
- Thêm tài liệu tham khảo vào `refs/references.bib` (BibLaTeX).
