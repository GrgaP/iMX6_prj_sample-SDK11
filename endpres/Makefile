TARGET?=main
LATEX_BUILD_CMD=pdflatex -interaction=nonstopmode

default: build slim notes

clean:
	mv FULogo_RGB.pdf FULogo_RGB
	rm -f *.acn *.acr *.alg *.aux *.bbl *.blg *.dvi *.glg *.glo *.gls *.ist *.lof *.log *.lol *.lot *.out *.toc *.nav *.snm *.vrb
	mv FULogo_RGB FULogo_RGB.pdf
build:
	make clean
	rm -f $(TARGET).pdf 
	$(LATEX_BUILD_CMD) $(TARGET).tex > /dev/null
	bibtex ${TARGET} || true
	$(LATEX_BUILD_CMD) $(TARGET).tex > /dev/null
	$(LATEX_BUILD_CMD) $(TARGET).tex > /dev/null
	@echo -------------------------------------------------------
	@echo Final run.
	$(LATEX_BUILD_CMD) $(TARGET).tex | grep 'Warning\|pages'
	make clean
slim:
	make clean
	echo hi > slim.pdf
	rm slim.pdf
	cat $(TARGET).tex | grep -v "\pause" > slim.tex
	$(LATEX_BUILD_CMD) slim.tex > /dev/null
	bibtex slim || true
	$(LATEX_BUILD_CMD) slim.tex > /dev/null
	$(LATEX_BUILD_CMD) slim.tex > /dev/null
	@echo -------------------------------------------------------
	@echo Final run.
	$(LATEX_BUILD_CMD) slim.tex | grep 'Warning\|pages'
	make clean
notes:
	./makenotesfrommain $(TARGET).tex notes.tex
	$(LATEX_BUILD_CMD) notes.tex > /dev/null
	bibtex notes || true
	$(LATEX_BUILD_CMD) notes.tex > /dev/null
	$(LATEX_BUILD_CMD) notes.tex > /dev/null
	$(LATEX_BUILD_CMD) notes.tex | grep 'Warning\|pages'
	make clean
	rm notes.tex
