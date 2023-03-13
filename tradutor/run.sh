clear
if flex scanner.l ; then
  if bison -vd parser.y ; then
    if gcc lex.yy.c parser.tab.c sym.c -o compiler -lfl ; then
      ./compiler < entrada.js
    fi
  fi
fi