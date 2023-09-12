#define M 100
#define N 100
#define P 100
struct admin {
	char admin_id[20];
	char admin_account[20];
	char admin_password[20];
	char admin_phone[12];
};
struct admin admins[M];

struct user
{
	char user_id[20];
	char user_account[20];
	char user_password[20];
	char user_phone[12];
};
struct user users[N];

struct cargo
{
	char cargo_id[20];
	char cargo_name[20];
	int cargo_quantity;
	char cargo_unit[20];
	char supplier_id[20];
};
struct cargo cargos[P];

struct cargoSold
{
	char cargoSold_id[20];
	char cargoSold_name[20];
	int cargoSold_quantity;
	char cargoSold_unit[20];
	char cargoSold_place[20];
	char user_id[20];
};
struct cargoSold cargoSolds[P];


struct supplier{
	char supplier_id[20];
	char supplier_name[60];
	char supplier_phone[12];
	char supplier_address[60];
};
struct supplier suppliers[P];

