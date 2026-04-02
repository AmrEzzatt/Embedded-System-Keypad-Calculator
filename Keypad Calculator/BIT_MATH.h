/*
 * BIT_MATH.h
 *
 * Created: 30/06/2024 1:33:13 pm
 *  Author: Amr Ezzat
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define setbit(Var,BitNo)   Var=Var|(1<<BitNo)
#define clrbit(Var,BitNo)   Var=Var&(~(1<<BitNo))
#define Togbit(Var,BitNo)   Var=Var^(1<<BitNo)
#define Getbit(Var,BitNo)   ((Var>>(BitNo))&1)



#endif /* BIT_MATH_H_ */