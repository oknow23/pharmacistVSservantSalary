#include <stdlib.h>
#include <stdio.h>

void main(void)
{
    int pharmacist = 62000;
    int servant = 46000;

    int differnce = pharmacist - servant;
    int year = 0;
    int lose = 0;
    float interest = 0;
    float rice_rate = 0.03;
    float bank_rate = 0.01;
    int pharmacist_sum = pharmacist;
    int servant_sum = servant;
    short int goal_flag = 0;
    short int goal2_flag = 0;

    printf("\n公務員薪水:%d 藥師薪水:%d 公務員調薪:%0.2f 銀行利率:%.2f\n\n", servant, pharmacist, rice_rate, bank_rate);

    while ((servant_sum < pharmacist_sum) || goal2_flag < 2)
    {
        servant = servant + servant * rice_rate;
        lose = lose + differnce * 12;
        differnce = differnce - (servant * rice_rate);
        ++year;
        printf("第 %d 年公務員調薪至: %d 元,與藥師薪水差額共 %d 元", year, servant, lose);

        /* calculate totoal salary */
        servant_sum = servant_sum + servant;
        pharmacist_sum = pharmacist_sum + pharmacist;

        interest = lose * bank_rate;
        lose = lose + interest;
        printf(", 差額銀行利息:%.0f 元\n", interest);

        if ((servant > pharmacist) && (goal_flag == 0))
        {
            goal_flag = 1;
            printf("\n要花%d年才會到達與藥師一樣的薪水%d，這%d年損失(薪水差額+銀行利息): %d 元\n\n", year, pharmacist, year, lose);
        }

        /* count last year to excice */
        if (servant_sum > pharmacist_sum)
            ++goal2_flag;
    }

    printf("\n公務員花%d年能跟藥師的總薪水打平\n\n", year);
}