paper = slide
$(paper).pdf: $(paper).tex
	pdflatex -shell-escape $(paper)

clean:
	rm -rf *.aux *.bbl *.blg *.log *.out *.pdf *.dot

all: $(paper).pdf

push:
	git pull --rebase origin master
	git push origin master

dependences:
	apt-get install texlive-latex-extra texlive-fonts-recommended texlive-latex-base 
