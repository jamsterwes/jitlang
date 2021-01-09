grammar JITLang;

// Combo of NL-terminated statements, comments, NLs, then possible a statement without a NL, then EOF
file: (statements+=stmt | '\n' | COMMENT)* (statements += stmt)? EOF;

stmt
    : expr
    | if_stmt
    | function_define
    | define
    | assign
    ;

// TODO: define functions with arguments, return type
function_define
    : 'fn' name=IDENT '(' typed_arg_list? ')' ('->' rettype=IDENT)? '\n'* '{' (statements+=stmt | '\n' | COMMENT)* '}'
    ;

if_stmt
    : 'if' '(' cond=expr ')' '\n'* '{' (statements+=stmt | '\n' | COMMENT)* '}'
    ;

define
    : name=IDENT ':' type=IDENT '=' value=expr
    ;

assign
    : name=IDENT '=' value=expr
    ;

expr
    : func_call                                 // funcCallExpr
    | atom                                      // atomExpr
    | expr postop=('++' | '--')                 // postExpr
    | preop=('++' | '--' | '!') expr            // preExpr
    | expr mult=('*' | '/' | '%') expr          // multExpr
    | expr add=('+' | '-') expr                 // addExpr
    | expr gt=('>' | '>=' | '<=' | '<') expr    // cmpGtExpr
    | expr eq=('==' | '!=') expr                // cmpEqExpr
    | '(' paren=expr ')'                        // parenExpr
    | expr logAnd=('&&' | AND) expr             // logAndExpr
    | expr logOr=('||' | OR) expr               // logOrExpr
    | cond=expr tern='?' t=expr ':' f=expr      // ternExpr
    ;

atom
    : literal                                   // constExpr
    | IDENT                                     // getVarExpr
    ;

typed_arg_list
    : (args+=typed_arg) (',' args+=typed_arg)*
    ;

typed_arg
    : name=IDENT ':' type=IDENT
    ;

arg_list
    : (args+=expr) (',' args+=expr)*
    ;

func_call
    : IDENT '(' arg_list ')'
    | IDENT '(' ')'
    ;

literal
    : NUMBER
    | STRING
    ;

AND : 'and';
OR : 'or';

IDENT
    : [a-zA-Z_][a-zA-Z0-9_]*
    ;

// String literal
STRING
    : '"' ( STRING_ESCAPE_SEQ | ~[\\\r\n"] )* '"'
    | '\'' ( STRING_ESCAPE_SEQ | ~[\\\r\n'] )* '\'' 
    ;

// Turns into a double
NUMBER
    : '-'? [0-9]+ ('.' [0-9]+)?
    ;

WHITESPACE
    : [ \t]+ -> skip
    ;

COMMENT
    : '//' ~[\r\n\f]*
    ;

fragment STRING_ESCAPE_SEQ
    : '\\' .
    ;