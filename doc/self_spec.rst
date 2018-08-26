JCFG grammar
============

Here is grammar of JCFG and it is specifies by JCFG itself. It
explains JCFG exactly after readers have few knowledge from `Section
6` and `Section 7`.

Although JCFG is Context Free Grammar, JCFG grammar can not be free
because limited of parsing techniques. JCFG grammar must be simple, so
parser can analysis an grammar without stuck. It is splits into two
parts: lexical and syntax.

.. code-block:: text

    // Part 1. Lexical

    ws = \0009 | \0020;
    // white space

    lower = \0061-007A;
    // lower case a-z

    newline = \000A | \000D;

    dec_digit = \0030-0039;
    // decimal digit

    hex_digit = dec_digit | 'A' | 'B' | 'C' | 'D' | 'E' | 'F';
    // heximal digit

    dec = dec_digit+;
    // decimal number

    hex = hex_digit+;
    // heximal number

    ncontrol = \0020-007E | \00A0-FFFFFFFF;
    // non control terminals

    inline_comment = '//' ncontrol* newline;
    // ex:  `// comment`

    block_comment = '/*' ncontrol* '*/';
    // ex: `/* comment */`

    // Part 2. Syntax

    term = '\' hex;
    // ex: `\12AF`

    term_range = '\' hex '-' hex;
    // ex: `\12AF-34AB`

    nterm = lower (lower | '_')*;
    // non terminal name

    rule = rule_lhs ws* '=' ws* rule_rhs ';';
    // ex: lower = \0061-007A

    rule_lhs = nterm;
    // left hand side of a rule

    rule_rhs = expr;
    // right hand side of a rule

    expr = term | term_range | nterm |
           expr_or | expr_seq |
           expr_rep | expr_star | expr_plus | expr_opt |
           expr_grp | str;
    // expression, perform operations between terminal and non terminal

    expr_or = expr ws* '|' ws* expr;
    // ex:  `expr | expr`

    expr_seq = expr ws+ expr;
    // ex: `expr expr`

    expr_rep = expr '{' dec [',' dec] '}';
    // ex: `expr{min,max}` or `expr{n}`

    expr_ast = expr '*';
    // ex: `expr*`

    expr_plus = expr '+';
    // ex:  `expr+`

    expr_opt = '[' ws* expr ws* ']';
    // ex:  `[expr]`

    expr_grp = '(' ws* expr ws* ')';
    // ex:  `(expr)`

    root_rule = 'root' ws* eq ws* expr semicolon;
    // ex:  `root = expr;`

    grammar = (rule | ws)* root_rule (rule | ws)*;
    // structure of an grammar
    // inline_comment and block_comment is not a part of grammar
