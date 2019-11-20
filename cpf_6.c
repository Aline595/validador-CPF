#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
bool ehdigito(char c){
	return (c >='0' && c <= '9');
}
int convertenumerico(char c){
	return c - '0';	
}
void converteentrada(char entrada[], int cpf[]){
	int i = strlen(entrada)-1,j = 10;
	while (i >=0){
		if(ehdigito(entrada[i])){
			cpf[j] = convertenumerico(entrada[i]);
			j--; 
		}
		i--;		
	}
	while (j>=0){
		cpf[j]=0;
		j--;
	}
}
bool verificadigito(int cpf[], int mult[],int n){
	int i ,soma=0;
	for(i=0;i<n;i++)
		soma = soma +cpf[i]*mult[i];
	int resto = ((soma*10)%11)%10;
	return resto == cpf[n];
}
int main (){
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i,j;
	char entrada[50];
	setlocale(LC_ALL,"portuguese");
	printf("Entre com os 11 dígitos do CPF:\n");
	gets (entrada);
	converteentrada(entrada,cpf);
	if(verificadigito(cpf,m1,9)&& verificadigito(cpf,m2,10)){
		printf("CPF valido\n");
		if(cpf[8]==0){
			printf("Rio grande do sul\n");
		}
		else if (cpf[8]==1){
			printf("Distrito federal, Goiás, Mato grosso, Mato Grosso do Sul e Tocantins\n");
		}
		else if(cpf[8]==2){
			printf("Amazonas, Pará, Roraima, Amapá, Acre e Rondônia\n");
		}
		else if(cpf[8]==3){
			printf("Ceará, Maranhão e Piauí\n");
		}
		else if(cpf[8]==4){
			printf("Paraiba, Pernambuco, Alagoas, Rio grande do norte\n");
		}	
		else if(cpf[8]==5){
			printf("Bahia, Sergipe\n");
		}
		else if (cpf[8]==6){
			printf("Minas gerais\n");
		}
		else if(cpf[8]==7){
			printf("Rio de janeiro, Espírito santo\n");
		}
		else if(cpf[8]==8){
			printf("São paulo\n");
		}
		else{
			printf("Paraná, Santa catarina\n");
		}
	}
	else printf("CPF inválido\n");	
	system("pause");	
	return 0;
}
