# Plugin Framework

## Resources

* [A Dr Dobb's Tutorial](http://www.drdobbs.com/dynamically-loaded-c-objects/184401900)
* [ROS' Class Loader](https://github.com/ros/class_loader)
* [ROS' PluginLib](https://github.com/ros/pluginlib)

## FAQ

### Open Questions

Mostly things I've read concerning the pitfalls or patterns you need to be wary
of, but haven't had the chance to investigate myself yet.

> Objects that are instantiated inside a dynamically loaded library must be deleted inside the same library. If the object is deleted inside the program itself, the results are unpredictable. It may work fine, or it may cause a memory leak or even a program crash. If your program redefines new or delete, a program crash is almost guaranteed...([reference](http://www.drdobbs.com/dynamically-loaded-c-objects/184401900), [example](http://www.drdobbs.com/dynamically-loaded-c-objects/184401900?pgno=4))

I don't think this is patently true. The important thing is the virtual chain of destructors.

> Can we load constructors with variable arguments? Might be possible with an argc, argv approach and doing the conversions in the plugin itself ([example (maybe)](http://www.drdobbs.com/dynamically-loaded-c-objects/184401900?pgno=5))

> Do plugin managers need to be singletons? What happens if two plugin managers try to load the same library?

> Creation of a loaded object typically yields a pointer to the base class. Can ownership instead be transferred to a shared/unique pointer?

ROS' class loader does this. How?

### Closed Questions