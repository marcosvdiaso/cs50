/*
Estou escrevendo comentário em português pois preciso conseguir acompanhar e armazenar meu
raciocinio Com português é bem mais prático
*/

/*
Primeiro implementar algoritmo de luhn para verificação da validade do cartão
Se o luhn for válido, verificar de qual bandeira é o cartão por meio dos requisitos
Se falhar no teste da bandeira ou do luhn, o cartão é invalido
*/

/* Para implementar luhn a primeira coisa que eu tenho que fazer é separar cada um dos digitos do
cartão para poder usa-los isoladamente na formula de validação
*/

#include <cs50.h>
#include <stdio.h>

int digitCounter(long credit);

int main()
{
    long credit;
    int digits[16];
    int dscalc[16];
    int ds = 0;
    int ss = 0;
    int vd;

    credit = get_long("Credit card number:");

    if (digitCounter(credit) == 14 || digitCounter(credit) < 13 || digitCounter(credit) > 16)
    /* Essa condicional é para verificar se tem menos 13 digitos ou se tem mais de 16 ou se tem 14*/
    {
        printf("INVALID\n");
    }
    else
    {
        /* Precisei criar essa variavel nd pois
        eu tentei colocar no loop "i < digitCounter(credit)" porém isso dava erro
        pois a cada vez que o credit era divido ele perdia um digito, e assim o digit counter
        diminuia assim o loop não completava pois o i o digit counter se igualavam na metade Porém
        com essa variável eu armazeno o digitcounter e assim tenho o valor estático para ser usado
        independente de modificações no credit */
        const int nd = digitCounter(credit);

        for (int i = 0; i < nd; i++)
        /*
        Nesse loop eu consigo armazenar cada um dos digitos do cartão em um espaço na array
        Isso é importante pois assim consigo isoladamente buscar cada um dos digitos
        para realizar as operações necessárias na validação de luhn
        */
        {
            digits[i] = credit % 10;
            credit /= 10;
        }

        for (int j = 1; j < nd; j += 2)
        /* Esse loop é para realização do primeiro passo da verificação de luhn*/
        /* o erro esta aqui eu estava multiplicando os valores e somando na variavel
        porem eu tenho que somar os digitos dos valores individulamente
        então se tiver um 12, eu não somo 12, eu somo 1 e 2 preciso resolver isso */
        /* Erro resolvido, basicamente o que esse loop faz agora é:
        1 - Pega o array de posição J de digits e multiplica por 2 e então atribui para o array
        de posição J da dscalc.
        2 - Se o valor atribuido for menor que 10 ele vai direto ser somado a variável DS.
        3 - Se o valor atribuido for maior ou igual a 10, então é feito o modulo do número (para
        separar o ultimo digito) e também é feita  divisão do número (para separar o primeiro
        digito), após isso ambos os digitos são somados e atribuidos a posição J de dscalc, após
        isso o valor é somado na variável DS. */
        {
            dscalc[j] = digits[j] * 2;
            if (dscalc[j] >= 10)
            {
                dscalc[j] = dscalc[j] % 10 + dscalc[j] / 10;
            }
            ds += dscalc[j];
        }

        for (int k = 0; k < nd; k += 2)
        /* Esse loop é para realização do segundo passo da verificação de luhn*/
        {
            ss += digits[k];
        }

        /* Ultimo passo da verificação de luhn
        Verificação do último digito*/
        vd = (ss + ds) % 10;
        if (vd == 0)
        {
            /* Após concluir a verificação de luhn, implementar agora a verificação de bandeira*/
            switch (nd)
            {
                case 13:
                    /* Para 13 digitos
                    Em 13 digitos temos apenas VISA
                    A regra para visa é começar com 4*/
                    if (digits[12] == 4)
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;
                case 15:
                    /* Para 15 digitos
                    Em 15 digitos temos apenas AMEX
                    A regra para amex é começar com 34 ou 37*/
                    if (digits[14] == 3)
                    {
                        if (digits[13] == 4 || digits[13] == 7)
                        {
                            printf("AMEX\n");
                        }
                        else
                        {
                            printf("INVALID\n");
                        }
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;
                case 16:
                    /* Para 16 digitos
                    Em 16 digitos temos VISA e MASTERCARD
                    A regra para visa é começar com 4
                    A regra para mastercard é começar com um numero entre 51 e 55*/
                    if (digits[15] == 4)
                    {
                        printf("VISA\n");
                    }
                    else if (digits[15] == 5)
                    {
                        if (digits[14] == 1 || digits[14] == 2 || digits[14] == 3 || digits[14] == 4 || digits[14] == 5)
                        {
                            printf("MASTERCARD\n");
                        }
                        else
                        {
                            printf("INVALID\n");
                        }
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int digitCounter(long credit)
/* Essa função é para contar quantos digitos tem o cartão */
{
    int counter = 0;

    if (credit == 0)
    {
        return 1;
    }

    while (credit != 0)
    {
        credit = credit / 10;
        counter++;
    }

    return counter;
}
