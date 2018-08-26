Grammar specfication
********************

Inline comment
==============

Syntax
------

.. code-block:: text

    // inline comment

Description
-----------

Write inline comment, it does not affect to grammar and be omitted.  `//`
open inline comment. `comment` is comment's content.  Comment's content is
terminate imediatly after line feed or enter character.

Example
-------

.. code-block:: text

    // This is inline comment

Block comment
=============

Syntax
------

.. code-block:: text

    /* block comment */

Description
-----------

Write block comment, it does not affect to grammar and be omitted.
`/*` open and `*/` close block comment. `comment` is comment's
content.

Example
-------

.. code-block:: text

    /*
    This is block comment
    It can be occurs in multi line
    */

Terminal
========

Syntax
------

.. code-block:: text

    \xxxx

Description
-----------

Produce a character match with code `xxxx` in Unicode. `\` is called
escape character. `xxxx` is uppercase hex code in Unicode.

Example
-------

.. code-block:: text

    \0000 is NULL character
    \0020 is space character
    \0061 is 'a' character
    \004D is 'D' character

Terminal range
==============

Syntax
------

.. code-block:: text

    \xxxx-yyyy

Description
-----------

Produce a character in range [xxxx, yyyy]. `\` is called escape
character. `-` is called range character. Both `xxxx` and `yyyy` is
uppercase hex code in Unicode. It is in range [0, +inf]. If `xxxx` =
`yyyy` then \xxxx-yyyy is equivalence with \xxxx and produce a
character. If `xxxx` < `yyyy` then it is invalid. If `xxxx` or `yyyy`
is out of range of Unicode, it is unspecified behavior.

Example
-------

.. code-block:: text

    \0030-0039 produces a digit
    \0041-005A produces a uppercase alphabets

Non terminal
============

Syntax
------

.. code-block:: text

    Sequence of terminal in ranges: \0041-005A - lowercase
    alphabets, \0030-0039 - digits and \5F - underscore. Start with
    lowercase alphabets.

Description
-----------

Specify non terminal, also called non terminal name.

Example
-------

.. code-block:: text

    lowercase
    number
    open_bracket

Rule
====

Syntax
------

.. code-block:: text

    rule_name = expr;

Description
-----------

Specify a rule. `rule_name` is non_terminal and it is compliant with
non terminal naming. `expr` is called expression. `expr` can be
terminal, terminal range, string or non_terminal. `expr` will be
specify particularly in next sections. `;` is called terminated
character. Between `rule_name` and `=` or between `=` and `expr` can
be empty, one or more of white space. `rule_name` can be repeat multi
times.

Example
-------

.. code-block:: text

    digit = \0030;
    lowercase = \0061-007A;
    uppercase = \0041-005A;
    alpha = lowercase;
    alpha = uppercase;
    encoding = 'UTF-8';
    encoding = 'UTF-16';
    encoding = 'UTF-32';

Expression
==========

Syntax
------

.. code-block:: text

    expr = terminal
    expr = terminal_range
    expr = non_terminal
    expr = expr_or
    expr = expr_concat
    expr = string
    expr = expr_rep
    expr = expr_ast
    expr = expr_plus
    expr = expr_opt

Description
-----------

terminal, terminal_range, non_terminal are specify in previous
sections. Rest of cases will be specific in next sections.

terminal expression is simple as below.

.. code-block:: text

    lowercase_a = \0061;

terminal_range expression is equivalence with list of rules contains
terminal expression:

.. code-block:: text

    lowercase = \0061-007A;

    is equivalence with

    lowercase = \0061;
    lowercase = \0062;
    ...
    lowercase = \007A;

non_terminal expression is simple as below:

.. code-block:: text

    rule = other_rule;

OR expression
=============

Syntax
------

.. code-block:: text

    expr_1 | expr_2 | ... | expr_i | ... | expr_n

Description
-----------

Produce a expression in set {expr_1, expr_2, ..., expr_i, ...,
expr_n}.  `expr_i`, i is in range [1, n] is called cases. `|` is
called union operation. Between `expr_i` and `|` can be empty, one or
more of white space.

Example
-------

.. code-block:: text

    one_or_two = one | two;
    one_or_two_or_three = one | two | three;

AND expression
==============

Syntax
------

.. code-block:: text

    expr_1 expr_2 ... expr_i ... expr_n

Description
-----------

Produce sequence of expressions. `expr_i`, i is in range [1, n] is
called parts. Between `expr_i` and `expr_i+1` can be one or more of
white space which represents for concatenation operation.

Example
-------

.. code-block:: text

    one_two = one two;
    one_two_three = one two three;

Loop expression
===============

Syntax
------

.. code-block:: text

    expr{min,max}
    expr{n}

Description
-----------

`expr{min,max}` produces sequence of `expr` in n times, n is in range
[min, max]. Both `min` and `max` is decimal, in range [0, +inf]. If
`min` = `max`, it produces sequenc of `expr` in n times exactly. If
`min` > `max`, it is invalid. `expr{min,max}` is equivalence with
`expr_concat` and multi rules:

.. code-block:: text

    less_than_3digits = digit{1,3};

    is equivalence with

    less_than_3digits = digit;
    less_than_3digits = digit digit;
    less_than_3digits = digit digit digit;

`expr{n}` is equivalence with `expr{n,n}`.

Example
-------

.. code-block:: text

    less_than_hundred = digit{1,2};
    produces 1, 2, ..., 99

    three_digits_number = digit{3,3};
    produces 111, 112, ..., 999

    three_digits_number = digit{3};
    produces 111, 112, ..., 999

Asterisk expression
===================

Syntax
------

.. code-block:: text

    expr*

It is equivalence with expr{0,+inf}.

Example
-------

.. code-block:: text

    empty_or_more_digits = digit*;
    produces empty terminal, 1, 12, 123, and so on

Plus expression
===============

Syntax
-------

.. code-block:: text

    expr+

It is equvalence with expr{1,+inf}.

Example
-------

.. code-block:: text

    one_or_more_digits = digit+;
    produces 1, 12, 123 and so on

Option expression
=================

Syntax
------

.. code-block:: text

    [expr]

It is equivalence with expr{0,1}.

Example
-------

.. code-block:: text

    one_or_not = [one];
    produce empty terminal or one

String
======

Syntax
------

.. code-block:: text

    'string'

Description
-----------

Specify a string. `'` is called single quote. `string` is sequence of
characters. String's character can be any characters, expcept single
quote and escape character. In string, single quote and escape
character must prefix by escape character such as '\'' and '\\'.

String is equivalence with concatnation of terminals:

.. code-block:: text

    encoding = 'UTF-8';

    is equivalence with

    encoding = \0055 \0054 \0046 \002D \0038;

Example
-------

.. code-block:: text

    'hello there, I am string'
    'string contains single quote: \''
    'string contains escape character: \\'

Root rule
=========

Syntax
------

.. code-block:: text

    root = expr;

Description
-----------

Specify special rule which is called root rule. If someone looks in
set of rules in the first time then they do not know what rule to
start. Root rule is standard, it allows they find a rule to start
imediately to save time and effort.

.. _spec_root_rule_ex:

Example
-------

.. code-block:: text

    math_expr = number;                     // integer number
    math_expr = math_expr opr math_expr;    // expr and operation
    opr = add | sub | mul | div;            // operation
    add = \002B;                            // +
    sub = \002D;                            // -
    mul = \002A;                            // *
    div = \002F;                            // /
    root = math_expr;                       // root rule

Grammar
=======

Syntax

.. code-block:: text

    rule_1
    rule_2
    ...
    root_rule
    rule_i
    ...
    rule_n

Description
-----------

Specify a Context Free Grammar by JCFG syntax. Grammar is set of rules
R = {root_rule, rule_1, ..., rule_i, ... rule_n} where i is in range
[1, n] and root_rule is mandatory.

Context Free Grammar is define by 4 tuples: G = (T, N, R, S), where T
is set of terminals, N is set of non_terminal, R is set of rules and S
is start rule. Surprise that JCFG contains only rules, but JCFG is not
wrong, it contains 4 tuples fully. In JCFG, T is set of Unicode
characters, R is defined, so N is also defined, S it root rule.

Example
-------

Refer to :ref:`spec_root_rule_ex`.
