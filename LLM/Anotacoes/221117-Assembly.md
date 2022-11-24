| # | Mnemônico | OpCode (hexadecimal) | Exemplo |
| - | - | - | - |
| 1 | MOV | 06 | MOV A,10 |
| 2 | MOV | 01 | MOV A,B |
| 3 | MOV | 07 | MOV 10,[35] |
| 4 | MOV | 04 | MOV [33],A |
| 5 | ADD | 0A | ADD A,B |
| 6 | MOV | 02 | MOV A,[25] |
| 7 | SUB | 0E | SUB A,B |
| 8 | DB | 1F | DB "String" |
| 9 | MUL | 3E | MUL [30] |
| 10 | MUL | 3C | MUL B |
| 11 | MUL | 3F | MUL 5 |
| 12 | INC | 12 | INC A |
| 13 | DEC | 13 | DEC A |
| 14 | JMP | 1E | JMP B |
| 15 | JMP | 1F | JMP 15 |
| 16 | CMP | 14 | CMP, A |
| 17 | JE |  |  |
| 18 | JME |  |  |
| 19 |  |  |  |

DB = DataByte

start:  
	MOV A,0  
	MOV C,3  
	CMP A,C  
	JE end  
loop:  
	INC A  
	CMP A,C  
	JNE loop  
end:  
	MOV [232],'O'  
	MOV [233],'K'  
	HLT  