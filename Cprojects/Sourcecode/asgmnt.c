#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
// structure of our subscriber
typedef struct{
    int id;
    float age;
    char *fullName;
    char *contact;
    char *address;
    char *healthHistory;
    char *subscribedPlan;
    char *subscribedPlanLimit;
} subscriber;
// structure of claim details
typedef struct{
    int idc;
    int userId;
    char *ward;
    int noOfDays;
    float costOfSupplies;
    float surgicalFees;
    float otherCharges;
    float claimableBalance;
    float claimedBalance;
    float excessBalance;
    char *claimLimit;
    struct date{
        int year;
        int month;
        int day;
        int hours;
        int min;
        int sec;
    }claimedDate;
} claim;
// store subscribers data in linked list data structure:
typedef struct subsList {
    subscriber *s;
    struct subsList *next;
}list;
// store Claims In linked list data Structure:
typedef struct claimList {
    claim *c;
    struct claimList *cnext;
}clist;
subscriber *planSubscription(list **head);
clist *claimProcessing(int userId,char *userPlan,char *userClaimLimit, list *head);
void getLtcInfo(clist *head); void searchSubs(list *head);
void getAclInfo(clist *head);
void insertIntoList(subscriber *s, list **head);
void insertClaimsIntoList(claim *c, clist **head);
subscriber *createSubscriber(int id,float age,char *fullName,char *contact,char *address,char *healthHistory,char* subscribedPlan,char *subscribedPlanLimit);
claim *createClaim(int idc,int userId,char *ward,int noOfDays,float costOfSupplies,float surgicalFees,float otherCharges,float claimableBalance,float claimedBalance, float excessAmount, char *userClaimLimit);
void saveSubscriberDetails(subscriber *s); void saveClaimDetails(claim *c);
void getPlans(float age);
void getBenifit(float age);
subscriber *getSubscriberDetails(list *subscribers, int subId);
void displaySubscriberDetails(subscriber *s);
void displayClaimDetails(claim *c);
subscriber *getSubsListById(list *head, int id); subscriber *getSubsListByName(list *head, char *name);subscriber *getSubsListByPlan(list *head, char *plan);
subscriber *getSubsListByClaimLimit(list *head, char *claimLimit); subscriber *getSubsListByAge(list *head, int age);
int main() {
	int id;
    list *head;
    subscriber *s;
    clist *c;
    char *choice[] = {"Accounts Information", "Search"};
    int cl, cw, pl, j,i = 0, userId;
    char *userPlan; char *userClaimLimit; int choiceInput;
    head = NULL;
    planSubscription(&head);
    printf("\t\t\t\t\t");
    printf("Please Enter User Id Of Which You Want To Make A Claim: ");
    scanf("%d", &id);
    s = getSubsListById(head, id);
    userId = s->id;
    userPlan = strdup(s->subscribedPlan);
    userClaimLimit = strdup(s->subscribedPlanLimit);
    c = claimProcessing(userId, userPlan, userClaimLimit, head);
    printf("\t\t\t\t\tPlease Select An Operation:?\n");
    printf("\t\t\t\t\tplease Press:\n");
    for(j = 0; j < 2; j++) {
        printf("\t\t\t\t\t%d for %s\n", j, choice[j]);
    }
    printf("\t\t\t\t\t");
    scanf("%d", &choiceInput);
    if(choiceInput == 0) {
//    	printf("Information Ran\n");
        getLtcInfo(c);
        getAclInfo(c);
        printf("Do You Want To Search For Subscribers?(Press 1 If You Want): ");
        scanf("%d", &choiceInput);
    }
	if(choiceInput == 1) {
        searchSubs(head);
    }
    return 0;
}
subscriber *planSubscription(list **head) {
    float age; char *fullName; char *address; char *contact; char *healthHistory;char clearBuffer;
    int cl, pl, j,i = 0;
    subscriber *s;char ch;
    char *claimLimits[] = {"Annual Claim Limit", "Lifetime Claim Limit"};char *plans[] = {"Plan120", "Plan150", "Plan200"};
    do {
         i++;
         printf("\t\t\t\t-------Before Any Claim please Subscribe to our plans-------\n\n");
         printf("\t\t\t\t\tTo subscribe plans, please enter your age: ");
         scanf("%f", &age);
         getPlans(age);
         printf("\t\t\t\t-------The claim Limits We Offering are:-------\n\n");
         printf("\t\t\t\t\tPlease press:\n");
         for(j = 0; j < 2; j++) {
             printf("\t\t\t\t\t%d for %s\n", j, claimLimits[j]);
         }
         printf("\t\t\t\t\t");
         scanf("%d", &cl);
         printf("\t\t\t\t\tPlease Subscribe To One Of Our Plans:\n\n");
         printf("\t\t\t\t\tPlease Press:\n");
         if(age>=0.0027 && age <= 20) {
	         for(j = 0; j < 3; j++) {
	             printf("\t\t\t\t\t%d for %s\n", j, plans[j]);
	         }
	     } else if(age>=21 && age <= 40) {
	     	for(j = 1; j < 3; j++) {
	             printf("\t\t\t\t\t%d for %s\n", j, plans[j]);
	         }
		 } else if(age>=41 && age <= 54) {
		 	for(j = 2; j < 3; j++) {
	             printf("\t\t\t\t\t%d for %s\n", j, plans[j]);
	         }
		 }
         printf("\t\t\t\t\t");
         scanf("%d", &pl);
         printf("\t\t\t\t\tPlease Fill Up The Follwing Details:\n");
         scanf("%c", &clearBuffer); //use to clear the buffer stored after fetching the integer
         printf("\t\t\t\t\tEnter your Full Name: ");
        //  %[^\n] this custom format specifier is used to store string with space.
         fullName = malloc(sizeof(char)*80); //allocate required memory 
         scanf("%[^\n]", fullName);
         scanf("%c", &clearBuffer);
         printf("\t\t\t\t\tEnter your Contact: ");
         contact = malloc(sizeof(char)*15);
         scanf("%[^\n]", contact);
         scanf("%c", &clearBuffer);
         printf("\t\t\t\t\tEnter your Address: ");
         address = malloc(sizeof(char)*200);
         scanf("%[^\n]", address);
         scanf("%c", &clearBuffer);
         printf("\t\t\t\t\tEnter your Health History: ");
         healthHistory = malloc(sizeof(char)*200);
         scanf("%[^\n]", healthHistory);
         s = createSubscriber(i, age, fullName, contact, address, healthHistory, plans[pl], claimLimits[cl]);
         insertIntoList(s, head);
         printf("\t\t\t\t\tYour Detail Is:\n");
         displaySubscriberDetails(s);
         saveSubscriberDetails(s);
         printf("\t\t\t\t\tDo You Want More Plan Subscriptions(Y/N)?\n");
         printf("\t\t\t\t\t");
         scanf("%c", &ch);
         if(ch == 'y' || ch == 'Y') {
            ;
         } else {

             return s;
         }
    } while(ch == 'y' || ch == 'Y');

}
clist *claimProcessing(int userId,char *userPlan,char *userClaimLimit, list *lhead) {
    claim *c;int cw, j , i = 0;char *wards[] = {"Normal Ward", "Intensive Care Unit(ICU)"};clist *head;
    int noOfDays; float costOfSupplies=0.00, surgicalFees=0.00, otherCharges=0.00, claimedAmount=0.00, claimableAmount=0.00, excessAmmount=0.00;
    head = NULL; char ch;int id; subscriber *s;
    do {
        i++;
        printf("\t\t\t----------Before Processing For Claim Please Provide Us Following Information--------------\n\n");
        printf("\t\t\t\t\tPlease Enter How Many Days You Were Hospitalised: ");
        scanf("%d", &noOfDays);
        printf("\t\t\t\t\tWhat Was Your Ward? Please Press:\n");
        for(j = 0; j<2; j++) {
            printf("\t\t\t\t\t%d For %s\n", j, wards[j]);
        }
        printf("\t\t\t\t\t");
        scanf("%d", &cw);
        printf("\t\t\t\t\tPlease Enter Total Cost of Supplies and Services: ");
        scanf("%f", &costOfSupplies);
        printf("\t\t\t\t\tPlease Enter Total Surgical Fees: ");
        scanf("%f", &surgicalFees);
        printf("\t\t\t\t\tPlease Enter Other Charges: ");
        scanf("%f", &otherCharges); 
        if(strcmp(userPlan, "Plan120")==0 && strcmp(userClaimLimit , "Annual Claim Limit")) {
            claimableAmount = 120000;
            claimedAmount = (cw == 0)?(noOfDays*120):(noOfDays*250);
            claimedAmount += (costOfSupplies + surgicalFees + otherCharges);
            if(claimedAmount > claimableAmount) {
                excessAmmount = claimedAmount - claimedAmount;
            } else {
                claimableAmount -= claimedAmount; 
            }
        } else if(strcmp(userPlan, "Plan120")==0 && strcmp(userClaimLimit , "Lifetime Claim Limit")) {
            claimableAmount = 600000;
            claimedAmount = (cw == 0)?(noOfDays*120):(noOfDays*250);
            if(claimedAmount > claimableAmount) {
                excessAmmount = claimedAmount - claimedAmount;
            } else {
                claimableAmount -= claimedAmount; 
            }
        } else if(strcmp(userPlan, "Plan150")==0 && strcmp(userClaimLimit , "Annual Claim Limit")) {
            claimableAmount = 150000;
            claimedAmount = (cw == 0)?(noOfDays*150):(noOfDays*400);
            if(claimedAmount > claimableAmount) {
                excessAmmount = claimedAmount - claimedAmount;
            } else {
                claimableAmount -= claimedAmount; 
            }
        } else if(strcmp(userPlan, "Plan150")==0 && strcmp(userClaimLimit , "Lifetime Claim Limit")) {
            claimableAmount = 750000;
            claimedAmount = (cw == 0)?(noOfDays*150):(noOfDays*400);
            if(claimedAmount > claimableAmount) {
                excessAmmount = claimedAmount - claimedAmount;
            } else {
                claimableAmount -= claimedAmount; 
            }
        } else if(strcmp(userPlan, "Plan200")==0 && strcmp(userClaimLimit , "Annual Claim Limit")) {
            claimableAmount = 200000;
            claimedAmount = (cw == 0)?(noOfDays*200):(noOfDays*700);
            if(claimedAmount > claimableAmount) {
                excessAmmount = claimedAmount - claimedAmount;
            } else {
                claimableAmount -= claimedAmount; 
            }
        } else if(strcmp(userPlan, "Plan200")==0 && strcmp(userClaimLimit , "Lifetime Claim Limit")) {
            claimableAmount = 1000000;
            claimedAmount = (cw == 0)?(noOfDays*200):(noOfDays*700);
            if(claimedAmount > claimableAmount) {
                excessAmmount = claimedAmount - claimedAmount;
            } else {
                claimableAmount -= claimedAmount; 
            }
        }
        if(excessAmmount > 0.000) {
            printf("\t\t\t\t\t-------------Claiming Process Failed!---------------");
            printf("\t\t\t\t\tYou Are Requesting For %f More Than Your Claimable Amount, SO Please Complete Your Payment First!");
        } else {
            c = createClaim(i, userId, wards[cw], noOfDays, costOfSupplies, surgicalFees, otherCharges, claimableAmount, claimedAmount, excessAmmount, userClaimLimit);
            displayClaimDetails(c);
            saveClaimDetails(c);
            insertClaimsIntoList(c, &head);
        }
         printf("\t\t\t\t\tDo You Want More Claim Submission(Y/N)?\n");
         printf("\t\t\t\t\t");
         scanf("%c", &ch);
         if(ch == 'y' || ch == 'Y') {
            printf("\t\t\t\t\t");
		    printf("Please Enter User Id Of Which You Want To Make A Claim: ");
		    scanf("%d", &id);
		    s = getSubsListById(lhead, id);
		    userId = s->id;
		    userPlan = strdup(s->subscribedPlan);
		    userClaimLimit = strdup(s->subscribedPlanLimit);
		    claimProcessing(userId, userPlan, userClaimLimit, lhead);
            return head;
         } else {
             return head;
         }
    } while(ch == 'y' || ch =='Y');
}
subscriber *createSubscriber(int id,float age,char *fullName,char *contact,char *address,char *healthHistory,char *subscribedPlan,char *subscribedPlanLimit) {
    subscriber *s = (subscriber *)malloc(sizeof(subscriber)); //typecasting is necessary from normal pointer returned by malloc to struct *
    s->id = id; //integer and characters are copeid directly.
    s->fullName = _strdup(fullName); //for strings, memory allocation is required, strdup simply  copies.
    s->age = age;
    s->contact = strdup(contact);
    s->address = strdup(address);
    s->healthHistory = strdup(healthHistory);
    s->subscribedPlan = strdup(subscribedPlan);
    s->subscribedPlanLimit = strdup(subscribedPlanLimit);
    return s;
}
void displaySubscriberDetails(subscriber *s) {
    printf("\t\t\t\t\t---------------------------------------------------------------\n");
    printf("\t\t\t\t\tid=%d\n\t\t\t\t\tFull-Name=%s\n\t\t\t\t\tage=%f\n\t\t\t\t\tcontact=%s\n\t\t\t\t\tAddress=%s\n\t\t\t\t\tHealth-History=%s\n\t\t\t\t\tPlan=%s\n\t\t\t\t\tClaim-Limit=%s\n", s->id, s->fullName, s->age, s->contact, s->address, s->healthHistory, s->subscribedPlan, s->subscribedPlanLimit);
}
void getPlans(float age) {
    printf("\n\t\t\t\t-------Valid Plans For This Subscriber Are:-------\n\n");
    if(age>=0.0027 && age <= 20) {
        printf("\t\t\t\t\t\t\t\tPlan120(RM)\tplan150(RM)\tPlan200(RM)\n");
        printf("\t\t\t\t\t----------------------------------------------------------------------\n");
        printf("\t\t\t\t\tMonthly Premium\t\t120\t\t150\t\t200\n");
        printf("\t\t\t\t\tAnnual Claim Limit\t120,000\t\t150,000\t\t200,000\n");
        printf("\t\t\t\t\tLifetime Claim Limit\t600,000\t\t750,000\t\t1,000,000\n\n");
        printf("\t\t\t-------Hospitalaisation And Surgical Benifits For This Subscriber Are:-------\n\n");
        getBenifit(age);
    }
    else if(age>=21 && age <= 40) {
        printf("\t\t\t\t\t\t\t\tplan150(RM)\tPlan200(RM)\n");
        printf("\t\t\t\t\t---------------------------------------------------\n");
        printf("\t\t\t\t\tMonthly Premium\t\t150\t\t200\n");
        printf("\t\t\t\t\tAnnual Claim Limit\t150,000\t\t200,000\n");
        printf("\t\t\t\t\tLifetime Claim Limit\t750,000\t\t1,000,000\n\n");
        printf("\t\t\t\t-------Hospitalaisation And Surgical Benifits For This Subscriber Are:-------\n\n");
        getBenifit(age);
    }
    else if(age>=41 && age <= 54) {
        printf("\t\t\t\t\t\t\t\tPlan200(RM)\n");
         printf("\t\t\t\t\t---------------------------------------------------\n");
        printf("\t\t\t\t\tMonthly Premium\t\t200\n");
        printf("\t\t\t\t\tAnnual Claim Limit\t200,000\n");
        printf("\t\t\t\t\tLifetime Claim Limit\t1,000,000\n\n");
        printf("\t\t\t\t-------Hospitalaisation And Surgical Benifits For This Subscriber Are:-------\n\n");
        getBenifit(age); 
    }
}
void getBenifit(float age) {
    if(age>=0.0027 && age <= 20) {
        printf("\t\t\t\t\tTypes Of Claim\t\t\tEligibility Ammount\n");
        printf("\t\t\t\t\t-----------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\tPlan120\t\tPlan150\t\tPlan200\n");
        printf("\t\t\t\t\t\t\t\t----------------------------------------\n");
        printf("\t\t\t\t\tRoom Charges\t\t120/day\t\t150/day\t\t200/day\n");
        printf("\t\t\t\t\tICU Charges\t\t250/day\t\t400/day\t\t700/day\n");
        printf("\t\t\t\t\tHospital Supplies\n");
        printf("\t\t\t\t\tAnd Services\t\t\t\t\t\n");
        printf("\t\t\t\t\tSurgical Fees\t\tAs charged subject to aproval by ZeeMediLife\n");
        printf("\t\t\t\t\tOther Fees\n\n");
    }
    else if(age>=21 && age <= 40) {
        printf("\t\t\t\t\tTypes Of Claim\t\tEligibility Ammount\n");
        printf("\t\t\t\t\t------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\tPlan150\t\tPlan200\n");
        printf("\t\t\t\t\t\t\t\t------------------------\n");
        printf("\t\t\t\t\tRoom Charges\t\t150/day\t\t200/day\n");
        printf("\t\t\t\t\tICU Charges\t\t400/day\t\t700/day\n");
        printf("\t\t\t\t\tHospital Supplies\n");
        printf("\t\t\t\t\tAnd Services\t\t\t\n");
        printf("\t\t\t\t\tSurgical Fees\t\tAs charged subject to aproval by ZeeMediLife\n");
        printf("\t\t\t\t\tOther Fees\n\n");
    }
    else if(age>=41 && age <= 54) {
        printf("\t\t\t\t\tTypes Of Claim\t\tEligibility Ammount\n");
        printf("\t\t\t\t\t------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\tPlan200\n");
        printf("\t\t\t\t\t\t\t\t-----------------------\n");
        printf("\t\t\t\t\tRoom Charges\t\t\t200/day\n");
        printf("\t\t\t\t\tICU Charges\t\t\t700/day\n");
        printf("\t\t\t\t\tHospital Supplies\n");
        printf("\t\t\t\t\tAnd Services\t\t\n");
        printf("\t\t\t\t\tSurgical Fees\t\tAs charged subject to aproval by ZeeMediLife\n");
        printf("\t\t\t\t\tOther Fees\n\n");
    }

}
void saveSubscriberDetails(subscriber *s) {
    FILE *filePtr;
    filePtr = fopen("E:/Cprojects/Subsdetails/Subscribers.txt", "a");
    if(filePtr == NULL) {
        printf("\nFile is Missing!");
        exit(0);
    }
    fprintf(filePtr,"\n--------- Subscriber Details ---------\n");
    fprintf(filePtr,"-------------------------------------------\n");
    fprintf(filePtr, "id=%d\nFull-Name=%s\nage=%f\ncontact=%s\nAddress=%s\nHealth-History=%s\nPlan=%s\nClaim-Limit=%s\n", s->id, s->fullName, s->age, s->contact, s->address, s->healthHistory, s->subscribedPlan, s->subscribedPlanLimit);
    fclose(filePtr);
    getchar();
}
void insertIntoList(subscriber *s, list **head) {
    list *temp;
    temp = (list*)malloc(sizeof(list));
    temp->s = s;
    temp->next = NULL;
    if(*head == NULL) {
        *head = temp;
    } else {
        list *temp2;
        temp2 = *head;
        while(temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}
subscriber *getSubsListById(list *head, int id) {
    list *temp;
    temp = head;
    if(temp == NULL) {
        printf("\t\t\t\t\tNo Subscribers!");
        return NULL;
    } else {
        while(temp != NULL) {
            if(temp->s->id == id) {
                displaySubscriberDetails(temp->s);
                return temp->s;
            }
            temp = temp->next;
        }
        return NULL;
    }
}
subscriber *getSubsListByName(list *head, char *name) {
    list *temp;
    temp = head;
    if(temp == NULL) {
        printf("\t\t\t\t\tNo Subscribers!");
        return NULL;
    } else {
        while(temp != NULL) {
            if(strcmp(temp->s->fullName, name) == 0) {
                displaySubscriberDetails(temp->s);
            }
            temp = temp->next;
        }
        return NULL;
    }
}
subscriber *getSubsListByPlan(list *head, char *plan) {
    list *temp;
    temp = head;
    if(temp == NULL) {
        printf("\t\t\t\t\tNo Subscribers!");
        return NULL;
    } else {
        while(temp != NULL) {
            if(strcmp(temp->s->subscribedPlan, plan) == 0) {
                displaySubscriberDetails(temp->s);
            }
            temp = temp->next;
        }
        return NULL;
    }
}
subscriber *getSubsListByClaimLimit(list *head, char *claimLimit) {
    list *temp;
    temp = head;
    if(temp == NULL) {
        printf("\t\t\t\t\tNo Subscribers!");
        return NULL;
    } else {
        while(temp != NULL) {
            if(strcmp(temp->s->subscribedPlanLimit, claimLimit) == 0) {
                displaySubscriberDetails(temp->s);
            }
            temp = temp->next;
        }
        return NULL;
    }
}
subscriber *getSubsListByAge(list *head, int age) {
    list *temp;
    temp = head;
    if(temp == NULL) {
        printf("\t\t\t\t\tNo Subscribers!");
        return NULL;
    } else {
        while(temp != NULL) {
            if(temp->s->age == age) {
                displaySubscriberDetails(temp->s);
            }
            temp = temp->next;
        }
        return NULL;
    }
}
claim *createClaim(int idc,int userId,char *ward,int noOfDays,float costOfSupplies,float surgicalFees,float otherCharges,float claimableBalance,float claimedBalance, float excessAmount, char *userClaimLimit) {
    claim *c;
    c = (claim *)malloc(sizeof(claim));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    c->idc = idc;
    c->userId = userId;
    c->ward = strdup(ward);
    c->noOfDays = noOfDays;
    c->costOfSupplies = costOfSupplies;
    c->surgicalFees = surgicalFees;
    c->otherCharges = otherCharges;
    c->claimableBalance = claimableBalance;
    c->claimedBalance = claimedBalance;
    c->claimedDate.year = tm.tm_year + 1900;
    c->claimedDate.month = tm.tm_mon + 1;
    c->claimedDate.day = tm.tm_mday;
    c->claimedDate.hours = tm.tm_hour;
    c->claimedDate.min = tm.tm_min;
    c->claimedDate.sec = tm.tm_sec;
    c->excessBalance = excessAmount;
    c->claimLimit = strdup(userClaimLimit);
    return c;
}
void saveClaimDetails(claim *c) {
    FILE *filePtr;
    filePtr = fopen("E:/Cprojects/Subsdetails/claims.txt", "a");
    if(filePtr == NULL) {
        printf("\nFile is Missing!");
        exit(0);
    }
    fprintf(filePtr,"\n--------- Claim Details ---------\n");
    fprintf(filePtr,"---------------------------------------------------------------\n");
    fprintf(filePtr, "claim Id=%d\nUser Id=%d\nWard=%s\nNo Of Days=%d\nCost Of Supplies=%f\nSurgical Fees=%f\nOther Charges=%f\nClaimable Balance=%f\nClaimed Balance = %f\nClaimed Date=%d-%02d-%02d\nClaimed Time=%02d:%02d:%02d\nExcess Balance=%f", c->idc,c->userId,c->ward,c->noOfDays,c->costOfSupplies,c->surgicalFees,c->otherCharges,c->claimableBalance, c->claimedBalance,c->claimedDate.year, c->claimedDate.month,c->claimedDate.day,c->claimedDate.hours,c->claimedDate.min, c->claimedDate.sec, c->excessBalance);
    fclose(filePtr);
    getchar();
}
void insertClaimsIntoList(claim *c, clist **head) {
    clist *temp;
    temp = (clist*)malloc(sizeof(clist));
    temp->c = c;
    temp->cnext = NULL;
    if(*head == NULL) {
        *head = temp;
    } else {
        clist *temp2;
        temp2 = *head;
        while(temp2->cnext != NULL) {
            temp2 = temp2->cnext;
        }
        temp2->cnext = temp;
    }
}
void displayClaimDetails(claim *c) {
    printf("\n\t\t\t\t\t--------- Claim Details ---------\n");
    printf("\t\t\t\t\tclaim Id=%d\n\t\t\t\t\tUser Id=%d\n\t\t\t\t\tWard=%s\n\t\t\t\t\tNo Of Days=%d\n\t\t\t\t\tCost Of Supplies=%f\n\t\t\t\t\tSurgical Fees=%f\n\t\t\t\t\tOther Charges=%f\n\t\t\t\t\tClaimable Balance=%f\n\t\t\t\t\tClaimed Balance=%f\n\t\t\t\t\tClaimed Date=%d-%02d-%02d\n\t\t\t\t\tClaimed Time=%02d:%02d:%02d\n\t\t\t\t\tExcess Balance=%f\n\n", c->idc,c->userId,c->ward,c->noOfDays,c->costOfSupplies,c->surgicalFees,c->otherCharges,c->claimableBalance,c->claimedBalance, c->claimedDate.year, c->claimedDate.month,c->claimedDate.day,c->claimedDate.hours,c->claimedDate.min, c->claimedDate.sec, c->excessBalance);
}
void getLtcInfo(clist *head) {
    float info = 0.00;
    clist *temp;
    temp = head;
    if(temp == NULL) {
    	printf("\t\t\t\t--------- No Data Found ---------\n");
    } else {
        while(temp != NULL) {
            if(strcmp(temp->c->claimLimit, "Lifetime Claim Limit") == 0) {
                info += temp->c->claimedBalance;
            }
            temp = temp->cnext;
        }
        printf("\n\t\t\t\t--------- Claim Details ---------\n");
        printf("\t\t\t\t---------------------------------------------------------------\n");
        printf("\t\t\t\tTotal amount claimed By Lifetime Limit Subscribers= %f", info);
    }
}
void getAclInfo(clist *head) {
    clist *temp;
    temp = head;
    int i = 0, j=0;
    if(temp == NULL) { 
        printf("\t\t\t\t--------- No Data Found ---------\n");
    } else {
        while(temp != NULL) {
            if(strcmp(temp->c->claimLimit, "Annual Claim Limit") == 0) {
                if(temp->c->claimableBalance <= 0) {
                	i++;
                }
            }
            temp = temp->cnext;
        }
        if(i>0) {
	        printf("\n\t\t\t\t--------- Total Number Of Annual Claims That Have axhausted All Their Eligible Amount ---------\n");
	        printf("\t\t\t\t---------------------------------------------------------------\n");
	        printf( "\t\t\t\tTotal Number Of Fully Serviced Subscribers = %d", i);
		} else {
			printf("\n\t\t\t\t---------No one has Exhausted All Their Eligible Amount---------\n");
		}
    }
}
void searchSubs(list *head) {
	float age;
    char choice;
    int i = 0;
    int ch;
    int id;
    char clearBuffer;
    char *name; char *plan;char *cl;
    char *searchingTags[] = {"id", "name", "plan", "claim Limit", "age"};
	do {
	    printf("\t\t\t\t-------What are you Going To Search With-------\n\n");
	    printf("\t\t\t\tPlease Press:\n");
	    for(i = 0; i < 5; i++) {
	        printf("\t\t\t\t%d For %s\n",i, searchingTags[i]);
	    }
	    printf("\t\t\t\t");
	    scanf("%d", &ch);
	    if(ch == 0) {
	        printf("\t\t\t\tPlease Enter User Id: ");
	        scanf("%d", &id);
	        getSubsListById(head, id);
	    } else if(ch == 1) {
	        scanf("%c", &clearBuffer);
	        printf("\t\t\t\tPlease Enter Users Full Name: ");
	        name = malloc(sizeof(char)*80);
	        scanf("%[^\n]", name);
	        getSubsListByName(head, name);
	    }
	    else if(ch == 2) {
	        scanf("%c", &clearBuffer);
	        printf("\t\t\t\tPlease Enter Users Plan(Plan120, Plan150, Plan200): ");
	        plan = malloc(sizeof(char)*80);
	        scanf("%[^\n]", plan);
	        getSubsListByPlan(head, plan);
	    }  else if(ch == 3) {
	        scanf("%c", &clearBuffer);
	        printf("\t\t\t\tPlease Enter Users Claim Limit(Lifetime Claim Limit, Annual Claim Limit): ");
	        cl = malloc(sizeof(char)*80);
	        scanf("%[^\n]", cl);
	        getSubsListByClaimLimit(head, cl);
	    }  else if(ch == 4) {
	        printf("\t\t\t\tPlease Enter Users age: ");
	        scanf("%f", &age);
	        getSubsListByAge(head, age);
	    }
	    scanf("%c", &clearBuffer);
		printf("\t\t\t\tDo You Want Any More Searches(Y/N)? ");
		scanf("%c", &choice);
	}while(choice == 'y' || choice =='Y');
}