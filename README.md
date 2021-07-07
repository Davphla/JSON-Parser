# JSON Parser in C

Here's an entirely hand made JSON Parser made in C made for Epitech's project !\
It was made and well used for the **my_rpg** project in order to get scripting working (Using Tiled as a map editor). :slightly_smiling_face:\
\
[![ReadMe Card](https://github-readme-stats.vercel.app/api/pin/?username=Davphla&repo=JSON-Parser&theme=gruvbox&hide_border=false)](https://github.com/Mikatech/my_rpg)

## How it works
This was all made using linked list and the super well explained [JSON Website](https://www.json.org/json-fr.html) that explains pretty much everything behind this parser.\
All the present function are based from this website, and pretty much just adapted from it
## Main function
**Checker :**
```C
pars_data_t *parser_json(char *filepath); // Used to transform any .json into a pars_data_t linked_list structures
void pars_data_destroy(pars_data_t *data); // Destroy and free the linked list

pars_data_t *json_search(pars_data_t *data, const char *to_find); // Gets the pointer to the corresponding data_name structures, or return NULL

```
**Writer :**
```C
int writer_json(char *filepath, pars_obj_t *obj, pars_data_t *data); // Used to transform any pars_data_t struct into a .json file
```

**Data structures :**
```C
typedef union values_s {
    int kint;
    double kfloat;
    char *kstr;
    pars_data_t *kobj;
} values_t;

typedef struct pars_data_s {
    char *data_name;
    type_t type;
    values_t values;
    struct pars_data_s *next;
} pars_data_t;
```
