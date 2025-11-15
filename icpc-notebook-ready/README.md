# ICPC Notebook (Vietnamese, Landscape, Ready-to-Build)

## Requirements
- TeX Live 2022+ (recommended 2024+)
- `latexmk`

## Build
```bash
make        # build PDF (XeLaTeX)
make clean  # clean aux files
```

## Notes
- Vietnamese is enabled via XeLaTeX + polyglossia.
- A4 landscape, 2 columns, small fonts (8pt). Adjust in `main.tex` if needed.
