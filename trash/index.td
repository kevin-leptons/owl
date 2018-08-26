node first-argument 
        argument
        argument
        ...
        argument

        body

name(so stupid project)
version(0.0.0)
licenses(GPLv2)
authors(Kevin, Hulk, Thor)

var author-age = 25
var author-gender = male
var author-address = Hoa Binh, Viet Nam


include 'chapter01/index.td'
include 'chapter02/index.td'

h1 'Introduction'

h1(Introduction)
        id introduction

p

        `v author-age` `v author-gender`
        `a http://google.com` `s what?`
        `a #introduction`
        BASIC. This display mode is applies for Smart Phones, Tablets where
        screen's width is narrow. In this mode, almost components are hidden
        to save space for content display. Hidden components are show when
        needed by two buttons in top-left and top-right. See more detail in
        `a #concept`

        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here

code c

        void do_some_thing();

p

        ohter description

img img/puppies.png

table

        name                    age             address
        ----------------------------------------------------------------------
        Kevin                   ?               ?
        Stuard                  ?               ?
        Bob                     ?               ?

img-list
        img/first.png
        img/second.png
        img/third.png

[include]
        chapter-1
        chapter-2
        chapter-3

[p]
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here
        
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here

[h1] Scope
        scope

[p]
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here
        and here

[code] c
        int do_something(void *p, double x) {

        }

        void work(int day) {

        }

[p]
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here
        and here

[code-include] src/vector.h

[code-include] src/vector.c

[code-include] src/long/long/long.........................................
/long-path/............................................/readme.txt
        markdown

[code-include] src/long.....................................................
/long/...............................................readme.txt
        rst

[h1] Context
        id context

[h2] computer
        id context-computer

[h2] programming
        id context-programming

[h2] library
        id context-library

[h2] package
        id context-package

[include] package.td

[h1] long long..............................................................
title long....................................................
and more long.....................................


[name] so stupid project
[version] 0.0.0
[license] GLPv2
[authors] Kevin Leptons, Hulk, Thor
[font] fonts/mono-space.ttf
[fg-color] #000000
[bg-color] #ffffff
[variable]
        author-age: 25
        author-gender: male
        author-address: Hoa Binh, Viet Nam


[h1] Introduction
        introduction

[b]

        bold text here

[p]

        [v author-gender] [v author-address]
        [a http://google.com] [b hello]
        [a introduction]
        BASIC. This display mode is applies for Smart Phones, Tablets where
        screen's width is narrow. In this mode, almost components are hidden
        to save space for content display. Hidden components are show when
        needed by two buttons in top-left and top-right. See more detail in
        [a concept]

        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here

[img] img/puppies.png

[table]

        name                    age             address
        ----------------------------------------------------------------------
        Kevin                   ?               ?
        Stuard                  ?               ?
        Bob                     ?               ?

[img-list]
        img/first.png
        img/second.png
        img/third.png

[include]
        chapter-1
        chapter-2
        chapter-3

[p]
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here
        
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here

[h1] Scope
        scope

[p]
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here
        and here

[code] c
        int do_something(void *p, double x) {

        }

        void work(int day) {

        }

[p]
        FULL. This display mode is applies for PCs where screen's width is
        enough to display contents and all of components. It makes accessing
        to contents and other resource more quickly. See more detail in
        :ref:`fx-doc-full-mode`.  content here and here
        and here

[code-include] src/vector.h

[code-include] src/vector.c

[code-include] src/long/long/long.........................................
/long-path/............................................/readme.txt
        markdown

[code-include] src/long.....................................................
/long/...............................................readme.txt
        rst

[h1] Context
        id context

[h2] computer
        id context-computer

[h2] programming
        id context-programming

[h2] library
        id context-library

[h2] package
        id context-package

[include] package.td

[h1] long long..............................................................
title long....................................................
and more long.....................................
