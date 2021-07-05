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
pars_data_t *parser_json(char *filepath);
void pars_data_destroy(pars_data_t *data);

pars_data_t *json_search(pars_data_t *data, const char *to_find);

```
**Writer :**
```
int writer_json(char *filepath, pars_obj_t *obj, pars_data_t *data);
```
