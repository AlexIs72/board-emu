       ORG 0

       DI
       JR L8065
 
       DEFB #FF,#FF,#FF,#FF,#FF,#FF,#FF,#FF
       DEFB #FF,#FF,#FF,#FF,#FF,#FF,#FF,#FF
       DEFB #FF,#FF,#FF,#FF,#FF,#FF,#FF,#FF
       DEFB #FF,#FF,#FF,#FF,#FF,#FF,#FF,#FF
       DEFB #FF,#FF,#FF,#FF,#FF,#FF,#FF,#FF
       DEFB #FF,#FF,#FF,#FF,#FF,#FF,#FF,#FF
       DEFB #FF,#FF,#FF,#FF,#FF

L8038  DI
       XOR A
       OUT (#FE),A
       LD BC,#0457
L803F  DEC BC
       LD A,B
       OR C
       JR NZ,L803F
       LD A,#FF
       OUT (#FE),A
       EX AF,AF'
       LD C,A
       EX AF,AF'
       LD D,8
L804D  LD A,#FF
       OUT (#FE),A
       LD B,#C8
       SRL C
       RR B
       DJNZ $
       XOR A
       OUT (#FE),A
       LD B,#20
       DJNZ $
       DEC D
       JR NZ,L804D
       EI
       HALT


L8065  DI
       LD SP,0
       XOR A
       EX AF,AF'
       LD HL,#4000
       LD DE,#4001
       LD BC,#4000
       LD A,0
       LD (HL),A
       LDIR
       LD HL,#4000
       LD BC,#4000
       LD D,0
L8081  XOR A
       XOR (HL)
       OR D
       LD D,A
       INC HL
       DEC BC
       LD A,B
       OR C
       JR NZ,L8081
       EX AF,AF'
       LD A,D
       EX AF,AF'


      LD HL,#4000
      LD DE,#4001
      LD BC,#4000
      LD A,#FF
      LD (HL),A
      LDIR
      LD HL,#4000
      LD BC,#4000
      LD D,0
L80A4 LD A,#FF
      XOR (HL)
      OR D
      LD D,A
      INC HL
      DEC BC
      LD A,B
      OR C
      JR NZ,L80A4
      EX AF,AF'
      OR D
      EX AF,AF'

      LD HL,#4000
      LD DE,#4001
      LD BC,#4000
      LD A,#55
      LD (HL),A
      LDIR
      LD HL,#4000
      LD BC,#4000
      LD D,0
L80C8 LD A,#55
      XOR (HL)
      OR D
      LD D,A
      INC HL
      DEC BC
      LD A,B
      OR C
      JR NZ,L80C8

      EX AF,AF'
      OR D
      EX AF,AF'

      LD HL,#4000
      LD DE,#4001
      LD BC,#4000
      LD A,#AA
      LD (HL),A
      LDIR
      LD HL,#4000
      LD BC,#4000
      LD D,0
L80EC LD A,#AA
      XOR (HL)
      OR D
      LD D,A
      INC HL
      DEC BC
      LD A,B
      OR C
      JR NZ,L80EC
      EX AF,AF'
      OR D
      EX AF,AF'
      EI
      HALT

