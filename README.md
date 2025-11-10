# MyString

**MyString** is a library in **C** that offers a powerful way to manipulate Strings.

> Project developed with a focus on learning software engineering in C, using TDD (Test-Driven Development), Doxygen documentation and semantic versioning (SemVer).

---

## Features

- Initialize and safely free strings (`init_string`, `initwp_string`, `del_string`);
- id_error's Getter (`gete_string`); 
- Phase's Getter (`getp_string`); 
- Assign and compare string values (`assign_string`, `equals_string`);
- Character count (`counter_string`);
- Concatenate two `MyString` objects (`concat_string`);
- To Uppercase (`touppercase_string`);
- Handle errors internally using `id_error`;
- Removing all spaces in the string (`remasp_string`);
- Removing all left spaces and some special character ('\\t', '\\r', '\\n') in the string (`lstrip_string`);
- Include usage examples for each feature (see `/example`);
- Fully tested with **Criterion** and documented with **Doxygen**.

---

## Documentation

To generate the documentation, you need to have **Doxygen** installed on your system.  
Once installed, run the following command in your terminal:

```bash
doxygen Doxyfile
```

This command will create a new folder named `docs/`, where you can find the generated HTML documentation inside the `html/` subdirectory.
To view it, open the `index.html` file in your browser.