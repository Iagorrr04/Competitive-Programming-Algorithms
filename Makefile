readme:
	python scripts/gen-readme.py > README.md


format:
	python3 scripts/format/format-algorithms.py --path ${CURDIR}/algorithms

notebook: format
	python3 scripts/notebook/gen.py --path ${CURDIR}/algorithms
	firefox notebook.pdf

notepdf:
	pdflatex -interaction=nonstopmode -halt-on-error ${CURDIR}/scripts/notebook/notebook.tex 

