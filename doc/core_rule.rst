Core rules
***********

This is pre-defined rules of JCFG. It can be use directly without
explicit definition because it is core rule of JCFG. User MUST NOT
re-define that rules. If user re-define that rules, parser MUST warn
that the rule names is reserved.

.. code-block:: text

    ; Part 1. ASCII rules

    nul     = \0000.                ; null character
    soh     = \0001.                ; start of header
    stx     = \0002.                ; start of text
    etx     = \0003.                ; end of text
    eot     = \0004.                ; end of transmission
    enq     = \0005.                ; enquiry
    ack     = \0006.                ; acknowledgment
    bel     = \0007.                ; bell
    bs      = \0008.                ; backspace
    ht      = \0009.                ; horizontal tab
    lf      = \000A.                ; line feed
    vt      = \000B.                ; vertical tab
    ff      = \000C.                ; form feed
    cr      = \000D.                ; carriage return
    so      = \000E.                ; shift out
    si      = \000F.                ; shift in
    dle     = \0010.                ; data link escape
    dc1     = \0011.                ; device control 1
    dc2     = \0012.                ; device control 2
    dc3     = \0013.                ; device control 3
    dc4     = \0014.                ; device control 4
    nak     = \0015.                ; negative acknowledgement
    syn     = \0016.                ; synchronous idle
    etb     = \0017.                ; end of transmission block
    can     = \0018.                ; cancel
    em      = \0019.                ; end of medium
    sub     = \001A.                ; substitute
    esc     = \001B.                ; escape
    fs      = \001C.                ; file separator
    gs      = \001D.                ; group separator
    rs      = \001E.                ; send/record separator
    us      = \001F.                ; unit separator
    sp      = \0020.                ; space
    em      = \0021.                ; [!] exclamation mark
    dq      = \0022.                ; ["] double quote
    ns      = \0023.                ; [#] number sign
    ds      = \0024.                ; [$] dollar sign
    pc      = \0025.                ; [%] percent
    aps     = \0026.                ; [&] ampersand
    sq      = \0027.                ; ['] single quote
    opr     = \0028.                ; [(] opening parenthesis
    cpr     = \0029.                ; [)] closing parenthesis
    ast     = \002A.                ; [*] asterisk
    pls     = \002B.                ; [+] plus
    cm      = \002C.                ; [,] comma
    min     = \002D.                ; [-] minus or dash
    dot     = \002E.                ; [.] dot
    fl      = \002F.                ; [/] forward slash
    d0      = \0030.                ; [0]
    d1      = \0031.                ; [1]
    d2      = \0032.                ; [2]
    d3      = \0033.                ; [3]
    d4      = \0034.                ; [4]
    d5      = \0035.                ; [5]
    d6      = \0036.                ; [6]
    d7      = \0037.                ; [7]
    d8      = \0038.                ; [8]
    d9      = \0039.                ; [9]
    cl      = \003A.                ; [:] colon
    sc      = \003B.                ; [;] semi-colon
    lt      = \003C.                ; [<] less than
    eq      = \003D.                ; [=] equal sign
    gt      = \003E.                ; [>] greater than
    qm      = \003F.                ; [?] question mark
    at      = \0040.                ; [@] at
    A       = \0041.                ; [A]
    B       = \0042.                ; [B]
    C       = \0043.                ; [C]
    D       = \0044.                ; [D]
    E       = \0045.                ; [E]
    F       = \0046.                ; [F]
    G       = \0047.                ; [G]
    H       = \0048.                ; [H]
    I       = \0049.                ; [I]
    J       = \004A.                ; [J]
    K       = \004B.                ; [K]
    L       = \004C.                ; [L]
    M       = \004D.                ; [M]
    N       = \004E.                ; [N]
    O       = \004F.                ; [O]
    P       = \0050.                ; [P]
    Q       = \0051.                ; [Q]
    R       = \0052.                ; [R]
    S       = \0053.                ; [S]
    T       = \0054.                ; [T]
    U       = \0055.                ; [U]
    V       = \0056.                ; [V]
    W       = \0057.                ; [W]
    X       = \0058.                ; [X]
    Y       = \0059.                ; [Y]
    Z       = \005A.                ; [Z]
    obk     = \005B.                ; [[] opening bracket
    bsl     = \005C.                ; [\] back slash
    cbk     = \005D.                ; []] closing bracket
    car     = \005E.                ; [^] caret
    und     = \005F.                ; [_] underscore
    ga      = \0060.                ; [`] grave accent
    a       = \0061.                ; [a]
    b       = \0062.                ; [b]
    c       = \0063.                ; [c]
    d       = \0064.                ; [d]
    e       = \0065.                ; [e]
    f       = \0066.                ; [f]
    g       = \0067.                ; [g]
    h       = \0068.                ; [h]
    i       = \0069.                ; [i]
    j       = \006A.                ; [j]
    k       = \006B.                ; [k]
    l       = \006C.                ; [l]
    m       = \006D.                ; [m]
    n       = \006E.                ; [n]
    o       = \006F.                ; [o]
    p       = \0070.                ; [p]
    q       = \0071.                ; [q]
    r       = \0072.                ; [r]
    s       = \0073.                ; [s]
    t       = \0074.                ; [t]
    u       = \0075.                ; [u]
    v       = \0076.                ; [v]
    w       = \0077.                ; [w]
    x       = \0078.                ; [x]
    y       = \0079.                ; [y]
    z       = \007A.                ; [z]
    obr     = \007B.                ; [{] opening brace
    vb      = \007C.                ; [|] vertical bar
    cbr     = \007D.                ; [}] closing brace
    til     = \007E.                ; [~] tilde
    del     = \007F.                ; delete

    ; Part 2. Common rules

    dec_digit       = \0030-0039;
    dec             = dec_digit+;
    hex_digit       = dec_digit | A | B | C | D | E | F;
    hex             = hex_digit+;

    lower           = \0061-007A;
    upper           = \0041-005A;
    alpha           = lower | upper;
    newline         = lf | cr;
    whitespace      = ht | sp;

    str             = squote str_c squote;
    str_char        = \0001-0026 | \0028-FFFFFFFF | str_squote;

                    // every terminals, except null and single quote
                    // single quote in string must be escape by `\'`

    str_squote     = back_slash squote;

                    // single quote in string `\'`

    control         = \0x0000-001F | \007F-009F;

                    // control terminals which can be print

    ncontrol        = \0020-007E | \00A0-FFFFFFFF;

                    // non control terminals
